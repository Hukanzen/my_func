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

# ファイル読み込み文字列で返す
sub load_file
{
	my ($pack_name,$file)=@_;
	my $data="";

	open(RF,$file);
	for(my $i=0;<RF>;$i++){
		$data.=$_;
	}
	close(RF);

	return $data;
}

# ファイル読み込みし，配列で返す
sub array_load_file
{
	my ($pack_name,$file)=@_;
	my @data="";

	open(RF,$file);
	for(my $i=0;<RF>;$i++){
		$data[$i]=$_;
	}
	close(RF);

	return @data;
}

# ファイルの内容を空にする
sub reset_file
{
	my ($pack_name,$file)=@_;
	open(WF,">",$file);
	close(WF);
}