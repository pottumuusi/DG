#!/usr/bin/perl

open(FH, $ARGV[0]) || die("Failed to open file");

while (<FH>) {
	$row = $_;

	if ("$row" =~ /lost:/) {
		if ("$row" !~ /lost: 0/) {
			die "Detected a memory leak";
		}
	}
}
