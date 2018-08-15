# printf
"By now, you must be fed up alternating the ft_putstr and ft_putnbr functions when doing your printing. Are you not allowed to use printf? You can recode yours! It will be a chance for you to discover a feature of the C language – variadic functions – and to practice detailed management of the printing options. You will then be allowed to use your ft_printf in all your future projects."

# architecture

1. Parsing the input
	* differenciate the string from the flags
	* create a structure to store the pieces of the existing string
	* create a structure to hold each flag and its corresponding arguments
	* manage errors in case of missing arguments
	* test each group for errors before trying to convert or anything

2. Applying the proper conversion
	* __%c:__ print a single character
	* __%d:__ print a decimal (base 10)
	* __%e:__ print an exponential floating-point
	* __%f:__ print a floating-point
	* __%g:__ print a general-format floating-point
	* __%i:__ print an integer (base 10)
	* __%o:__ print a number in octal (base 8)
	* __%s:__ print a string of characters
	* __%u:__ print an unsigned decimal (base 10)
	* __%x:__ print a number in hexadecimal (base 16)
	* __%%:__ print a percent sign

3. Formatting the output

4. Joining the string together
