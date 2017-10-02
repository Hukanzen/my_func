package my_package.pm

# 第一引数には，パッケージ名($pack_name)が入る
# メゾッド -> メゾッドの場合，明示的に渡す

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

# ファイルに書き足す
sub put_file
{
	my ($pack_name,$file,$data)=@_;
	open(WF,">>",$file);
	print WF $data;
	close(WF);
}


# config ファイル
my $conf_file;

# config ファイルを決定する
sub set_conf
{
	my ($pack_name,$file)=@_;

	$conf_file=$file;
}

# コンフィグファイルから指定の値を取得する.
sub get_conf
{
	my ($pack_name,$str)=@_;

	# EXPR の中のすべての ASCII 非英数字キャラクタをバックスラッシュで エスケープしたものを返します。 
	# (つまり、/[A-Za-z_0-9]/ にマッチしない全ての ASCII 文字の前には ロケールに関わらずバックスラッシュが前置されます。)
	# これは、ダブルクォート文字列での \Q エスケープを実装するための 内部関数です。 
	$str=quotemeta(${str});

	my $cnf=$conf_file;
	
	my @data=array_load_file($pack_name,$cnf);
	my $BEGIN=0;

	foreach(@data){
		if($_ eq "BEGIN"){
			# BEGINから以下を読み込む
			$BEGIN=1;
			next;
		}

		if($BEGIN==0 or $_=~ m/^#/){
			next;
		}elsif($_ eq "END"){
			# ENDから以下は読みこまない
			last;
		}elsif($_=~m/${str}/){
			# 指定された項目の値を取得し、返す
			$_=~s/^${str}\s*=\s*//i;
			$_=~s/\n//;
			return $_;
		}
	}
}