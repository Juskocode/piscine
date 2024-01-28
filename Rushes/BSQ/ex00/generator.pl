#!/usr/bin/perl
use warnings;
use strict;

# Check if three arguments are provided
die "Usage: program x y density" unless (scalar(@ARGV) == 3);

# Assign command line arguments to variables
my ($x, $y, $density) = @ARGV;

# Print the header
print "$y.ox\n";

# Generate the grid
for (my $i = 0; $i < $y; $i++) {
    for (my $j = 0; $j < $x; $j++) {
        # Randomly determine whether to print "o" or "."
        if (int(rand($y) * 2) < $density) {
            print "o";
        } else {
            print ".";
        }
    }
    # Move to the next line after printing a row
    print "\n";
}
