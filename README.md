libconfigread
=============

A [libconfig](http://www.hyperrealm.com/libconfig/) compatible reader for bash.

This is a work in progress, an example use case for libconfigread would be:

```
$ cat myconfig.cfg
# An example libconfig configuration file
groceries = {
    fruit    = "apples";
    veg      = "potatoes";
    meat     = "beef";
};
$ libconfigread myarray < myconfig.cfg
$ echo ${!myarray[@]}
groceries,veg groceries,fruit groceries,meat
$ echo ${myarray[groceries,fruit]}
apples
$ echo ${myarray[groceries,veg]}
potatoes
$ echo ${myarray[groceries,meat]}
beef
```
