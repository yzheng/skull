#include <stdlib.h>

#include <skull/txn.h>

#include "txn_idldata.h"
#include "module_loader.h"
#include "module_executor.h"

using namespace skullcpp;

void   skull_module_init   (void* md)
{
    module_data_t* mdata = (module_data_t*)md;
    mdata->init(mdata->config);
}

void   skull_module_release(void* md)
{
    module_data_t* mdata = (module_data_t*)md;
    mdata->release();
}

int    skull_module_run    (void* md, skull_txn_t* txn)
{
    // 1. deserialize the binary data to user layer structure
    skullcpp::Txn uTxn(txn);

    // 2. run module
    module_data_t* mdata = (module_data_t*)md;
    int ret = mdata->run(uTxn);
    return ret;
}

size_t skull_module_unpack (void* md, skull_txn_t* txn,
                            const void* data, size_t data_len)
{
    // 1. prepare a fresh new user layer idl structure
    skullcpp::Txn uTxn(txn);

    // 2. run unpack
    module_data_t* mdata = (module_data_t*)md;
    size_t consumed_sz = mdata->unpack(uTxn, data, data_len);
    return consumed_sz;
}

void   skull_module_pack   (void* md, skull_txn_t* txn,
                            skull_txndata_t* txndata)
{
    // 1. Create txn and txndata
    skullcpp::Txn uTxn(txn, true);
    skullcpp::TxnData uTxnData(txndata);

    // 2. run pack
    module_data_t* mdata = (module_data_t*)md;
    mdata->pack(uTxn, uTxnData);
}
