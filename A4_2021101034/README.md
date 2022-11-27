<!-- file is written in markdown format -->

```
OS:Linux
```

# ***Section 1 :***

### **question 1 , 2:**

there are 2 modes in the .c file , 
define "first" (line 5) to overwrite the existing data in the output file / undefine "first" to append new observation to the end of output file.

```
$ gcc 1.c -o a.out
$ ./a.out <output file name>

$ gcc 2.c -o a.out
$ ./a.out <output file name>
```

### **question 3:**

the estimations of pi is printed for every power of 2 upto 10^6 in both output file and stdout(terminal)
```
$ gcc 3.c -o a.out
$ ./a.out <output file name>
```


# ***Section 2:***

### **question 4:**

``` 
$ gcc 4a.c -o a.out
$ ./a.out <input_file_name> <output_file_name>

$ gcc 4b.c -o a.out
$ ./a.out <data_file_name> <mean_file_name> <output_file_name>

$ gcc 4c.c -o a.out
$ ./a.out <data_file_name> <mean_file_name> <output_file_name>
```

### **approximate variance:**

* define "met1" (line 3) to find variance using Σ(x-x̄)^2/n here x̄ is mean upto that point,
* define "met2" (line 4) to find variance using (Σx^2)/n - (x̄)^2 here x̄ is mean upto that point
* both should not be defined at the same time (output will be crooked)
* output will be printed on screen in a new line for all i  from 1 to N
```
$ gcc appx_var.c -o a.out
$ ./a.out <input data file>
```

# ***Section 3:***

### **question 5a:**

output is printed on screen.
```
$  gcc 5a.c -o a.out
$ ./a.out
```

### **question 5b:**

output is printed on screen.
```
$ gcc 5b.c -o a.out
$ ./a.out
```

### **question 5c:**
```
$ gcc 5c_encrypt.c -o a
$ ./a <message> <key> <encrypted output>

$ gcc 5c_decrypt.c -o b
$ ./b <generated key> <encypted message> <decrypted output>
```

# ***Section 4:***

### **question 6,7,8:**
* programmes will add a newline at the end of txt file
```
$ gcc 6.c -o a.out
$ ./a.out <NAME OF FILE WHERE OUTPUT IS TO BE WRITTEN> <SPACE SEPARATED LIST OF INPUT FILES>

$ gcc 7.c -o a.out
$ ./a.out <NAME OF FILE WHERE OUTPUT IS TO BE WRITTEN> <SPACE SEPARATED LIST OF INPUT FILES>

$ gcc 8.c -o a.out
$ ./a.out <input_file 1> <input_file 2> <output_file_name>
```

