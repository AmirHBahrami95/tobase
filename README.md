# tobase
change representation of numbers to binary,octet or hex (basically 2-16 bases) all at the same time

## usage
like any other c program, just do:

```bash
$ make
```

or if you want to test it:

```bash
$ make run
```

and if you are on linux (with bash) you can export the command to your bashrc file:

```bash
$ make export
$ tobase 1200
```

you can pass multiple arguments and any argument which isn't a flag (and must be numeric)
is considered an input to get the bases for. so for instance

```bash
$ tobase 1200 2400 33 16
```

will give you

```bash
base10 bin oct hex
1200 10010110000 2260 4b0
2400 100101100000 4540 960
33 100001 41 21
16 10000 20 10
```
## options
you can get a list of options and how to use the program with __-h__ or __--help__ flag

### separator
the default output is space separated bc I personally like to work with awk and other
tools on linux to extract the values, you can change that by setting the flag __-s__ or __--separator__:

```bash
$ tobase 1200 -s ,
base10,bin,oct,hex
1200,10010110000,2260,4b0
```
### no-headers
you can disable showing headers output with __--no-headers__ or __-nh__:

```bash
$ tobase 1200 -nh 
1200 10010110000 2260 4b0
```

__CHEERS!__
