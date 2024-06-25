#!/usr/bin/perl
use strict;
use warnings;

# Compile the C++ program
my $compile_cmd = 'g++ main.cpp gillette_stadium.cpp -o stadium_boundary';
my $compile_output = `$compile_cmd`;

# Check if compilation was successful
if ($? == 0) {
    print "Compilation successful.\n";
    # Run the compiled program
    my $run_cmd = './stadium_boundary';
    system($run_cmd);
} else {
    print "Compilation failed.\n";
    print "Output: $compile_output\n";
}
