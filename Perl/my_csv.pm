package my_csv;

use strict;
use warnings;
use Data::Dumper;

sub new
{
	my $class = shift;
    my $self = {}; #hash
    return bless $self, $class;
}

sub read
{
	my $self=shift;
	my $fname=shift;
	
	$self->{FILENAME}=$fname;
	
	my $i=-1;
	open(FP,$fname) or die "cant get File open ";
	while(<FP>){
		$i++;
		chomp;
    	my @data = split(/,/, $_);
		my $data_l=@data;
		my @colmun;
		
		if($i==0){
			# 1行目から項目を読み取る
			foreach my $col (@data){
				push(@colmun,$col);
			}

			next;
		}
		
		foreach my $col (@colmun){
			$self->{$col}{$i}=pop(@data);
		}
		print Dumper @data;

		
	}
	close(FP);
	$self->{LENGTH}=$i;
}

sub get_length
{
	my $self=shift;
	
	return $self->{LENGTH};
}

1;