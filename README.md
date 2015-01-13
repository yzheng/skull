[![Build Status](https://travis-ci.org/finaldie/skull.svg?branch=0.4)](https://travis-ci.org/finaldie/skull)

skull
=====

Fast to start-up, easy to maintain, high productivity server framework.

## How to Build
Use Ubuntu14.04 as an example.

### Install dependencies
```
apt-get install libyaml-dev libpcap0.8-dev libpcap0.8 libprotobuf-c0 libprotobuf-c0-dev protobuf-c-compiler python-yaml

git clone git@github.com:finaldie/skull.git
cd skull
git submodule update --init --recursive
make dep
```

### Build Release Version
```
make -j4
```

### Build Debug Version
```
make debug=true -j4
```

### Install Skull and its related Scripts
```
sudo make install
```

## Start with a Skull Project
Now, skull environment has been set up, so let's create a Skull project and play
with it.

### Create Skull Project
```
skull create test_proj
```

### Add a Module
```
skull module --add
```

### Build Skull Project
```
skull build
```

### Deploy Skull Project
```
skull deploy

```

### Start Skull
```
skull start
```

## Frequent Questions
