package my_package.pm

sub new
{

}

# 改行をなくす関数(CRLFとLF両方対応)
sub rmv_newline
{
	my ($pack_name,$src)=@_;
	$src=~s/[\r]?\n//g;
	return ;
}