{
"cmd" : ["g++ -DLOCAL -Wall -std=c++14 $file_name -o $file_base_name && timeout 10s ./$file_base_name<inputf.in>outputf.in"], 
"selector" : "source.c",
"shell": true,
"working_dir" : "$file_path"
}
// g++ helloworld.cpp -o hello
// ./hello <input.txt>output.txt