//----------------------------------------------------------------------------------------------
//_bwb_scale.h
//		by	青い白熊		(bluewhitebear@hotmail.com)
//		Hp	Blue Darkness	(http://www.nothing-kb.jp/~bluedarkness/)
//----------------------------------------------------------------------------------------------
//値系転調
Int	BS_RENEWAL_IKEY=0;			//半音転調の値１
Int	BS_RENEWAL_IKEY_2=0;			//半音転調の値２
Int	BS_RENEWAL_IKEY_3=0;			//半音転調の値３
Int	BS_RENEWAL_FKEY=0;			//５度転調で転調する値
Int	BS_RENEWAL_FVAL=0;			//５度転調で代入された値
Int	BS_RENEWAL_TKEY=0;			//短３度転調で転調する値
Int	BS_RENEWAL_TVAL=0;			//短３度転調で代入された値
Int	BS_RENEWAL_OKEY=0;			//オクターブシフトでシフトする値
//Flag宣言系転調
Int	BS_RENEWAL_FKRR=0;			//その調の根音
Int	BS_RENEWAL_FKRC=0;			//その調の根音のプラスマイナス補正
Int	BS_RENEWAL_FKRP=0;			//その調の実際の転調具合
Array	BS_RENEWAL_FLAG=0,0,0,0,0,0,0;	//調のキーフラグ
Str	BS_RENEWAL_MK={Ｃ　};			//調名
//スケール
Array	BS_RENEWAL_SLAG=0,0,0,0,0,0,0;	//スケールのキーフラグ
Str	BS_RENEWAL_MS={Ionian(Major)};	//スケール名
Int	BS_RENEWAL_SMMS=0;			//Major:0 Minor:1
Int	BS_RENEWAL_SNNM=7;			//スケールの音数
Str	BS_RENEWAL_SNSM={cdefgab};		//スケールの音
Str	BS_RENEWAL_SEXN={};			//８音以上のスケールの時に追加するノート
Array	BS_RENEWAL_SPBE=0,0,0,0,0,0,0		//スケール修正
Array	BS_RENEWAL_SMBF=100,100,100,100,100	//スケールメモリー
Int	BS_RENEWAL_SMSW=on;			//スケールメモリースイッチ
//変数クリア
Function BS_CLEAR(){
	BS_RENEWAL_IKEY=0;			//半音転調の値１(BS_K)
	BS_RENEWAL_IKEY_2=0;			//半音転調の値２(BS_K2)
	BS_RENEWAL_IKEY_3=0;			//半音転調の値３(BS_K3)
	BS_RENEWAL_FKEY=0;			//５度転調で転調する値(BS_FK)
	BS_RENEWAL_FVAL=0;			//５度転調で代入された値(BS_FK)
	BS_RENEWAL_TKEY=0;			//短３度転調で転調する値(BS_TK)
	BS_RENEWAL_TVAL=0;			//短３度転調で代入された値(BS_TK)
	BS_RENEWAL_OKEY=0;			//オクターブシフトでシフトする値(BS_O)
	BS_RENEWAL_FKRR=0;			//その調の根音(BS_C,BS_Cp...)
	BS_RENEWAL_FKRC=0;			//その調の根音のプラスマイナス補正(BS_C,BS_Cp...)
	BS_RENEWAL_FKRP=0;			//その調の実際の転調具合(BS_C,BS_Cp...)
	BS_RENEWAL_FLAG=0,0,0,0,0,0,0;	//調のキーフラグ(BS_C,BS_Cp...)
	BS_RENEWAL_MK={Ｃ　};			//調名(BS_C,BS_Cp...)
	BS_RENEWAL_SLAG=0,0,0,0,0,0,0;	//スケールのキーフラグ(BS_MODE...)
	BS_RENEWAL_MS={Ionian(Major)};	//スケール名(BS_MODE...)
	BS_RENEWAL_SMMS=0;			//Major:0 Minor:1(BS_MODE...)
	BS_RENEWAL_SNNM=7;			//スケールの音数(BS_MODE...)
	BS_RENEWAL_SNSM={cdefgab};		//スケールの音(BS_MODE...)
	BS_RENEWAL_SEXN={};			//８音以上のスケールの時に追加するノート(BS_MODE...)
	BS_RENEWAL_SPBE=0,0,0,0,0,0,0		//スケール修正(BS_MODE...)
	BS_RENEWAL_SMBF=100,100,100,100,100	//スケールメモリー(BS_MODE...)
	BS_RENEWAL_SMSW=on;			//スケールメモリースイッチ(BS_SCALE_UNDO)
	}
//デバッグ用変数表示機構
Function BS_DEBUG_PRINT(){
	Print({"[現在のグローバル変数の状況]"})
	Print({"IKEY(半音転調の値１)			:"}+BS_RENEWAL_IKEY);
	Print({"IKEY_2(半音転調の値２)			:"}+BS_RENEWAL_IKEY_2);
	Print({"IKEY_3(半音転調の値３)			:"}+BS_RENEWAL_IKEY_3);
	Print({"FKEY(５度転調で転調する値)		:"}+BS_RENEWAL_FKEY);
	Print({"FVAL(５度転調で代入された値)		:"}+BS_RENEWAL_FVAL);
	Print({"TKEY(短３度転調で転調する値)		:"}+BS_RENEWAL_TKEY);
	Print({"TVAL(短３度転調で代入された値)		:"}+BS_RENEWAL_TVAL);
	Print({"OKEY(オクターブシフトでシフトする値)	:"}+BS_RENEWAL_OKEY);
	Print({"FKRR(その調の根音)			:"}+BS_RENEWAL_FKRR);
	Print({"FKRC(その調の根音のプラスマイナス補正)	:"}+BS_RENEWAL_FKRC);
	Print({"FKRP(その調の実際の転調具合)		:"}+BS_RENEWAL_FKRP);
	Print({"FLAG(調のキーフラグ)			:"}+BS_RENEWAL_FLAG);
	Print({"MK(調名)					:"}+BS_RENEWAL_MK);
	Print({"SLAG(スケールのキーフラグ)		:"}+BS_RENEWAL_SLAG);
	Print({"MS(スケール名)				:"}+BS_RENEWAL_MS);
	Print({"SMMS(Major:1 Minor:2)			:"}+BS_RENEWAL_SMMS);
	Print({"SNNM(スケールの音数)			:"}+BS_RENEWAL_SNNM);
	Print({"SNSM(スケールの音)			:"}+BS_RENEWAL_SNSM);
	Print({"SEXN(追加するノート)			:"}+BS_RENEWAL_SEXN);
	Print({"SPBE(スケール修正)			:"}+BS_RENEWAL_SPBE);
	Print({"SMBF(スケールメモリー)			:"}+BS_RENEWAL_SMBF);
	Print({"SMSW(スケールメモリースイッチ)		:"}+BS_RENEWAL_SMSW);
	}

//変数をまとめ、実際に転調を行う
Function BS_RENEWAL(Int BS_RENEWAL_EDIT_I){
	Array BS_RENEWAL_A=0,0,0,0,0,0,0;

	If(BS_RENEWAL_EDIT_I==0){BS_RENEWAL_SPBE=0,0,0,0,0,0,0;}
	For(Int BS_F=0;BS_F<7;BS_F++){
		BS_RENEWAL_A(BS_F)=BS_RENEWAL_A(BS_F)+BS_RENEWAL_FLAG(BS_F)
		BS_RENEWAL_A(BS_F)=BS_RENEWAL_A(BS_F)+BS_RENEWAL_SLAG((BS_F-BS_RENEWAL_FKRR+7)%7)
		BS_RENEWAL_A(BS_F)=BS_RENEWAL_A(BS_F)+BS_RENEWAL_SPBE((BS_F-BS_RENEWAL_FKRR+7)%7);
		BS_RENEWAL_A(BS_F)=BS_RENEWAL_A(BS_F)+BS_RENEWAL_IKEY+BS_RENEWAL_IKEY_2+BS_RENEWAL_IKEY_3
		BS_RENEWAL_A(BS_F)=BS_RENEWAL_A(BS_F)+BS_RENEWAL_FKRC
		BS_RENEWAL_A(BS_F)=BS_RENEWAL_A(BS_F)+(BS_RENEWAL_OKEY*12)
		BS_RENEWAL_A(BS_F)=BS_RENEWAL_A(BS_F)+BS_RENEWAL_FKEY+BS_RENEWAL_TKEY
		}

	TimeKeyFlag(,,(BS_RENEWAL_A))
	}
//メタイベント書きこみ機能
Function BS_META(){	//メタイベント書きこみ機能
	Int	BS_META_K=(BS_RENEWAL_FKRP+BS_RENEWAL_TKEY+BS_RENEWAL_FKEY+BS_RENEWAL_IKEY+BS_RENEWAL_IKEY_2+BS_RENEWAL_IKEY_3)%12;
	If(BS_RENEWAL_SMMS==1){BS_META_K=BS_META_K+3;}
	BS_META_K=BS_META_K%12;
	If(BS_META_K<0){BS_META_K=BS_META_K+12}
	Int	BS_META_N=0;
	
	Switch(BS_META_K){
		Case( 0){BS_META_N=0;}
		Case( 1){BS_META_N=-5;}
		Case( 2){BS_META_N=2;}
		Case( 3){BS_META_N=-3;}
		Case( 4){BS_META_N=4;}
		Case( 5){BS_META_N=-1;}
		Case( 6){BS_META_N=-6;}
		Case( 7){BS_META_N=1;}
		Case( 8){BS_META_N=-4;}
		Case( 9){BS_META_N=3;}
		Case(10){BS_META_N=-2;}
		Case(11){BS_META_N=5;}
		}

	DirectSMF($FF,$59,$02,BS_META_N,BS_RENEWAL_SMMS);
	}

//表示機能
Function BS_PRINT(){	//表示機能
	Int	BS_PRINT_K=(BS_RENEWAL_FKRP+BS_RENEWAL_TKEY+BS_RENEWAL_FKEY+BS_RENEWAL_IKEY+BS_RENEWAL_IKEY_2+BS_RENEWAL_IKEY_3)%12;
	Str	BS_PRINT_N;
	Int	BS_PRINT_AK=BS_RENEWAL_TKEY+BS_RENEWAL_FKEY+BS_RENEWAL_IKEY+BS_RENEWAL_IKEY_2+BS_RENEWAL_IKEY_3+(BS_RENEWAL_OKEY*12)

	If(BS_PRINT_K<0){BS_PRINT_K+=12;}
	Switch(BS_PRINT_K){
		Case( 0){BS_PRINT_N={"Ｃ　"}}
		Case( 1){BS_PRINT_N={"Ｄ♭"}}
		Case( 2){BS_PRINT_N={"Ｄ　"}}
		Case( 3){BS_PRINT_N={"Ｅ♭"}}
		Case( 4){BS_PRINT_N={"Ｅ　"}}
		Case( 5){BS_PRINT_N={"Ｆ　"}}
		Case( 6){BS_PRINT_N={"Ｇ♭"}}
		Case( 7){BS_PRINT_N={"Ｇ　"}}
		Case( 8){BS_PRINT_N={"Ａ♭"}}
		Case( 9){BS_PRINT_N={"Ａ　"}}
		Case(10){BS_PRINT_N={"Ｂ♭"}}
		Case(11){BS_PRINT_N={"Ｂ　"}}
		}
	
Str	BS_PRINT_1={"キー：("}+BS_RENEWAL_MK+{")"}+{"				オクターブシフト(BS_O)："}+BS_RENEWAL_OKEY;
Str	BS_PRINT_2={"短３度転調(BS_TK)："}+BS_RENEWAL_TVAL+{"×3→"}+BS_RENEWAL_TKEY+{"		５度転調(BS_FK)："}+BS_RENEWAL_FVAL+{"×5％12→"}+BS_RENEWAL_FKEY;
Str	BS_PRINT_3={"半音転調(BS_K,BS_K2,BS_K3)：("}+BS_RENEWAL_IKEY+{","}+BS_RENEWAL_IKEY_2+{","}+BS_RENEWAL_IKEY_3+{")"}+{"	スケール修正値：("}+BS_RENEWAL_SPBE(0)+{","}+BS_RENEWAL_SPBE(1)+{","}+BS_RENEWAL_SPBE(2)+{","}+BS_RENEWAL_SPBE(3)+{","}+BS_RENEWAL_SPBE(4)+{","}+BS_RENEWAL_SPBE(5)+{","}+BS_RENEWAL_SPBE(6)+{")"};
Str	BS_PRINT_4={"スケール："}+BS_RENEWAL_MS+{"("}+BS_RENEWAL_SLAG(0)+{","}+BS_RENEWAL_SLAG(1)+{","}+BS_RENEWAL_SLAG(2)+{","}+BS_RENEWAL_SLAG(3)+{","}+BS_RENEWAL_SLAG(4)+{","}+BS_RENEWAL_SLAG(5)+{","}+BS_RENEWAL_SLAG(6)+{")("}+BS_RENEWAL_SNNM+{"音)"};
Str	BS_PRINT_5={"スケールの構成音："}+{"("}+BS_RENEWAL_SNSM+{"):("}+BS_RENEWAL_SEXN+{")"};
Str	BS_PRINT_6={"現在の結果：Key：["}+BS_PRINT_N+{"]	転調値：["}+BS_PRINT_AK+{"]"};
	Print({"[現在のパラメータ(Time:"}+Time+{")]"})
	Print(BS_PRINT_1)
	Print(BS_PRINT_2)
	Print(BS_PRINT_3)
	Print(BS_PRINT_4)
	Print(BS_PRINT_5)
	Print(BS_PRINT_6)
	}

//関数郡
Function BS_K(Int BS_I){	BS_RENEWAL_IKEY=BS_I;					BS_RENEWAL(0);}	//(Int BS_I=転調する値)
Function BS_KEY(Int BS_I){	BS_RENEWAL_IKEY=BS_I;					BS_RENEWAL(0);}	//(Int BS_I=転調する値)
Function BS_UP(){			BS_RENEWAL_IKEY+=1;					BS_RENEWAL(0);}	//１半音上に転調
Function BS_KUP(){		BS_RENEWAL_IKEY+=1;					BS_RENEWAL(0);}	//１半音上に転調
Function BS_DOWN(){		BS_RENEWAL_IKEY-=1;					BS_RENEWAL(0);}	//１半音下に転調
Function BS_KDOWN(){		BS_RENEWAL_IKEY-=1;					BS_RENEWAL(0);}	//１半音下に転調
Function BS_K2(Int BS_I){	BS_RENEWAL_IKEY_2=BS_I;					BS_RENEWAL(0);}	//(Int BS_I=転調する値)
Function BS_KEY2(Int BS_I){	BS_RENEWAL_IKEY_2=BS_I;					BS_RENEWAL(0);}	//(Int BS_I=転調する値)
Function BS_K2UP(){		BS_RENEWAL_IKEY_2+=1;					BS_RENEWAL(0);}	//１半音上に転調
Function BS_K2DOWN(){		BS_RENEWAL_IKEY_2-=1;					BS_RENEWAL(0);}	//１半音下に転調
Function BS_K3(Int BS_I){	BS_RENEWAL_IKEY_3=BS_I;					BS_RENEWAL(0);}	//(Int BS_I=転調する値)
Function BS_KEY3(Int BS_I){	BS_RENEWAL_IKEY_3=BS_I;					BS_RENEWAL(0);}	//(Int BS_I=転調する値)
Function BS_K3UP(){		BS_RENEWAL_IKEY_3+=1;					BS_RENEWAL(0);}	//１半音上に転調
Function BS_K3DOWN(){		BS_RENEWAL_IKEY_3-=1;					BS_RENEWAL(0);}	//１半音下に転調
Function BS_O(Int BS_I){	BS_RENEWAL_OKEY=BS_I;					BS_RENEWAL(0);}	//(Int BS_I=上下させるオクターブ)
Function BS_OCTAVE(Int BS_I){	BS_RENEWAL_OKEY=BS_I;					BS_RENEWAL(0);}	//(Int BS_I=上下させるオクターブ)
Function BS_OUP(){		BS_RENEWAL_OKEY+=1;					BS_RENEWAL(0);}	//１オクターブ上へ
Function BS_ODOWN(){		BS_RENEWAL_OKEY-=1;					BS_RENEWAL(0);}	//１オクターブ下へ
Function BS_FK(Int BS_I){	BS_RENEWAL_FVAL=BS_I;BS_RENEWAL_FKEY=BS_I*5%12;
					If(BS_RENEWAL_FKEY>6){BS_RENEWAL_FKEY-=12;}	BS_RENEWAL(0);}	//(Int BS_I=５度圏(5半音上)転調させる値)
Function BS_FKEY(Int BS_I){	BS_RENEWAL_FVAL=BS_I;BS_RENEWAL_FKEY=BS_I*5%12;
					If(BS_RENEWAL_FKEY>6){BS_RENEWAL_FKEY-=12;}	BS_RENEWAL(0);}	//(Int BS_I=５度圏(5半音上)転調させる値)
Function BS_TK(Int BS_I){	BS_RENEWAL_TVAL=BS_I;BS_RENEWAL_TKEY=BS_I*3;	BS_RENEWAL(0);}	//(Int BS_I=短３度転調させる値)
Function BS_TKEY(Int BS_I){	BS_RENEWAL_TVAL=BS_I;BS_RENEWAL_TKEY=BS_I*3;	BS_RENEWAL(0);}	//(Int BS_I=短３度転調させる値)

Function BS_Cb(){	BS_RENEWAL_FLAG=-0,-0,-0,-0,-0,-0,-0;BS_RENEWAL_FKRR= 0;BS_RENEWAL_FKRC=-1;BS_RENEWAL_FKRP=-1;BS_RENEWAL_MK={Ｃ♭};BS_RENEWAL(0);}	//キーをＢ　に
Function BS_C(){	BS_RENEWAL_FLAG=-0,-0,-0,-0,-0,-0,-0;BS_RENEWAL_FKRR= 0;BS_RENEWAL_FKRC= 0;BS_RENEWAL_FKRP= 0;BS_RENEWAL_MK={Ｃ　};BS_RENEWAL(0);}	//キーをＣ　に
Function BS_Cp(){	BS_RENEWAL_FLAG=-0,-0,-0,-0,-0,-0,-0;BS_RENEWAL_FKRR= 0;BS_RENEWAL_FKRC= 1;BS_RENEWAL_FKRP= 1;BS_RENEWAL_MK={Ｃ♯};BS_RENEWAL(0);}	//キーをＣ♯に
Function BS_Db(){	BS_RENEWAL_FLAG=-0,-0,+1,-0,-0,+1,-0;BS_RENEWAL_FKRR= 1;BS_RENEWAL_FKRC=-1;BS_RENEWAL_FKRP= 1;BS_RENEWAL_MK={Ｄ♭};BS_RENEWAL(0);}	//キーをＤ♭に
Function BS_D(){	BS_RENEWAL_FLAG=-0,-0,+1,-0,-0,+1,-0;BS_RENEWAL_FKRR= 1;BS_RENEWAL_FKRC= 0;BS_RENEWAL_FKRP= 2;BS_RENEWAL_MK={Ｄ　};BS_RENEWAL(0);}	//キーをＤ　に
Function BS_Dp(){	BS_RENEWAL_FLAG=-0,-0,+1,-0,-0,+1,-0;BS_RENEWAL_FKRR= 1;BS_RENEWAL_FKRC= 1;BS_RENEWAL_FKRP= 3;BS_RENEWAL_MK={Ｄ♯};BS_RENEWAL(0);}	//キーをＤ♯に
Function BS_Eb(){	BS_RENEWAL_FLAG=-0,-0,+1,+1,-0,+1,+1;BS_RENEWAL_FKRR= 2;BS_RENEWAL_FKRC=-1;BS_RENEWAL_FKRP= 3;BS_RENEWAL_MK={Ｅ♭};BS_RENEWAL(0);}	//キーをＥ♭に
Function BS_E(){	BS_RENEWAL_FLAG=-0,-0,+1,+1,-0,+1,+1;BS_RENEWAL_FKRR= 2;BS_RENEWAL_FKRC= 0;BS_RENEWAL_FKRP= 4;BS_RENEWAL_MK={Ｅ　};BS_RENEWAL(0);}	//キーをＥ　に
Function BS_Ep(){	BS_RENEWAL_FLAG=-0,-0,+1,+1,-0,+1,+1;BS_RENEWAL_FKRR= 2;BS_RENEWAL_FKRC= 1;BS_RENEWAL_FKRP= 5;BS_RENEWAL_MK={Ｅ♯};BS_RENEWAL(0);}	//キーをＦ　に
Function BS_Fb(){	BS_RENEWAL_FLAG=-0,-1,-0,-0,-0,-0,-0;BS_RENEWAL_FKRR= 3;BS_RENEWAL_FKRC=-1;BS_RENEWAL_FKRP= 4;BS_RENEWAL_MK={Ｆ♭};BS_RENEWAL(0);}	//キーをＥ　に
Function BS_F(){	BS_RENEWAL_FLAG=-0,-1,-0,-0,-0,-0,-0;BS_RENEWAL_FKRR= 3;BS_RENEWAL_FKRC= 0;BS_RENEWAL_FKRP= 5;BS_RENEWAL_MK={Ｆ　};BS_RENEWAL(0);}	//キーをＦ　に
Function BS_Fp(){	BS_RENEWAL_FLAG=-0,-1,-0,-0,-0,-0,-0;BS_RENEWAL_FKRR= 3;BS_RENEWAL_FKRC= 1;BS_RENEWAL_FKRP= 6;BS_RENEWAL_MK={Ｆ♯};BS_RENEWAL(0);}	//キーをＦ♯に
Function BS_Gb(){	BS_RENEWAL_FLAG=-0,-0,-0,-0,-0,+1,-0;BS_RENEWAL_FKRR= 4;BS_RENEWAL_FKRC=-1;BS_RENEWAL_FKRP= 6;BS_RENEWAL_MK={Ｇ♭};BS_RENEWAL(0);}	//キーをＧ♭に
Function BS_G(){	BS_RENEWAL_FLAG=-0,-0,-0,-0,-0,+1,-0;BS_RENEWAL_FKRR= 4;BS_RENEWAL_FKRC= 0;BS_RENEWAL_FKRP= 7;BS_RENEWAL_MK={Ｇ　};BS_RENEWAL(0);}	//キーをＧ　に
Function BS_Gp(){	BS_RENEWAL_FLAG=-0,-0,-0,-0,-0,+1,-0;BS_RENEWAL_FKRR= 4;BS_RENEWAL_FKRC= 1;BS_RENEWAL_FKRP= 8;BS_RENEWAL_MK={Ｇ♯};BS_RENEWAL(0);}	//キーをＧ♯に
Function BS_Ab(){	BS_RENEWAL_FLAG=-0,-0,+1,-0,-0,+1,+1;BS_RENEWAL_FKRR= 5;BS_RENEWAL_FKRC=-1;BS_RENEWAL_FKRP= 8;BS_RENEWAL_MK={Ａ♭};BS_RENEWAL(0);}	//キーをＡ♭に
Function BS_A(){	BS_RENEWAL_FLAG=-0,-0,+1,-0,-0,+1,+1;BS_RENEWAL_FKRR= 5;BS_RENEWAL_FKRC= 0;BS_RENEWAL_FKRP= 9;BS_RENEWAL_MK={Ａ　};BS_RENEWAL(0);}	//キーをＡ　に
Function BS_Ap(){	BS_RENEWAL_FLAG=-0,-0,+1,-0,-0,+1,+1;BS_RENEWAL_FKRR= 5;BS_RENEWAL_FKRC= 1;BS_RENEWAL_FKRP=10;BS_RENEWAL_MK={Ａ♯};BS_RENEWAL(0);}	//キーをＡ♯に
Function BS_Bb(){	BS_RENEWAL_FLAG=+1,-0,+1,+1,-0,+1,+1;BS_RENEWAL_FKRR= 6;BS_RENEWAL_FKRC=-1;BS_RENEWAL_FKRP=10;BS_RENEWAL_MK={Ｂ♭};BS_RENEWAL(0);}	//キーをＢ♭に
Function BS_B(){	BS_RENEWAL_FLAG=+1,-0,+1,+1,-0,+1,+1;BS_RENEWAL_FKRR= 6;BS_RENEWAL_FKRC= 0;BS_RENEWAL_FKRP=11;BS_RENEWAL_MK={Ｂ　};BS_RENEWAL(0);}	//キーをＢ　に
Function BS_Bp(){	BS_RENEWAL_FLAG=+1,-0,+1,+1,-0,+1,+1;BS_RENEWAL_FKRR= 6;BS_RENEWAL_FKRC= 1;BS_RENEWAL_FKRP=12;BS_RENEWAL_MK={Ｂ♯};BS_RENEWAL(0);}	//キーをＣ　に

Function BS_SCALE_UNDO(Int BS_SCALE_UNDO_R){	//スケールを戻す
	If(BS_SCALE_UNDO_R==0){	BS_RENEWAL_SMBF(0)=BS_RENEWAL_SMBF(1);
					BS_RENEWAL_SMBF(1)=BS_RENEWAL_SMBF(2);
					BS_RENEWAL_SMBF(2)=BS_RENEWAL_SMBF(3);
					BS_RENEWAL_SMBF(3)=BS_RENEWAL_SMBF(4);
					BS_RENEWAL_SMBF(4)=100;}
	If(BS_SCALE_UNDO_R>0){
		For(Int BS_SCALE_UNDO_F=0;BS_SCALE_UNDO_F<BS_SCALE_UNDO_R;BS_SCALE_UNDO_F++){
			BS_RENEWAL_SMBF(0)=BS_RENEWAL_SMBF(1);
			BS_RENEWAL_SMBF(1)=BS_RENEWAL_SMBF(2);
			BS_RENEWAL_SMBF(2)=BS_RENEWAL_SMBF(3);
			BS_RENEWAL_SMBF(3)=BS_RENEWAL_SMBF(4);
			BS_RENEWAL_SMBF(4)=100;}
				}

	BS_RENEWAL_SMSW=off;
	
	Switch(BS_RENEWAL_SMBF(0)/100){
	Case(1){BS_MODE(BS_RENEWAL_SMBF(0)%100)}
	Case(2){BS_HMINOR(BS_RENEWAL_SMBF(0)%100)}
	Case(3){BS_MMINOR(BS_RENEWAL_SMBF(0)%100)}
	Case(4){BS_OTHER(BS_RENEWAL_SMBF(0)%100)}
	Case(5){BS_WORLD(BS_RENEWAL_SMBF(0)%100)}
		}
	}
Function BS_SCALE_MEMORY(Int BS_SCALE_MEMORY_I){
	Switch(BS_RENEWAL_SMSW){
	Case(on){
	BS_RENEWAL_SMBF(4)=BS_RENEWAL_SMBF(3);
	BS_RENEWAL_SMBF(3)=BS_RENEWAL_SMBF(2);
	BS_RENEWAL_SMBF(2)=BS_RENEWAL_SMBF(1);
	BS_RENEWAL_SMBF(1)=BS_RENEWAL_SMBF(0);
	BS_RENEWAL_SMBF(0)=BS_SCALE_MEMORY_I;
		}
	Case(off){BS_RENEWAL_SMSW=on;}
		}
	}

Function BS_MODE(Int BS_I){Switch(BS_I){	//モード（教会旋法）スケールへ
Case(00){BS_SCALE_MEMORY(100);BS_RENEWAL_SLAG=0,0,0,0,0,0,0;	BS_RENEWAL_SMMS=0;BS_RENEWAL_SNNM=7;BS_RENEWAL_SEXN={};		BS_RENEWAL_SNSM={cdefgab};		BS_RENEWAL_MS={Ionian(Major)};}
Case(01){BS_SCALE_MEMORY(101);BS_RENEWAL_SLAG=0,-1,0,0,-1,0,0;	BS_RENEWAL_SMMS=1;BS_RENEWAL_SNNM=7;BS_RENEWAL_SEXN={};		BS_RENEWAL_SNSM={cde-fgab-};		BS_RENEWAL_MS={Dorian};}
Case(02){BS_SCALE_MEMORY(102);BS_RENEWAL_SLAG=-1,-1,0,-1,-1,0,0;	BS_RENEWAL_SMMS=1;BS_RENEWAL_SNNM=7;BS_RENEWAL_SEXN={};		BS_RENEWAL_SNSM={cd-e-fga-b-};	BS_RENEWAL_MS={Phrygian};}
Case(03){BS_SCALE_MEMORY(103);BS_RENEWAL_SLAG=0,0,0,0,0,1,0;	BS_RENEWAL_SMMS=0;BS_RENEWAL_SNNM=7;BS_RENEWAL_SEXN={};		BS_RENEWAL_SNSM={cdef+gab};		BS_RENEWAL_MS={Lydian};}
Case(04){BS_SCALE_MEMORY(104);BS_RENEWAL_SLAG=0,-1,0,0,0,0,0;	BS_RENEWAL_SMMS=0;BS_RENEWAL_SNNM=7;BS_RENEWAL_SEXN={};		BS_RENEWAL_SNSM={cdefgab-};		BS_RENEWAL_MS={Mixolydian};}
Case(05){BS_SCALE_MEMORY(105);BS_RENEWAL_SLAG=-1,-1,0,0,-1,0,0;	BS_RENEWAL_SMMS=1;BS_RENEWAL_SNNM=7;BS_RENEWAL_SEXN={};		BS_RENEWAL_SNSM={cde-fga-b-};		BS_RENEWAL_MS={Aeolian(Minor)};}
Case(06){BS_SCALE_MEMORY(106);BS_RENEWAL_SLAG=-1,-1,0,-1,-1,0,-1;	BS_RENEWAL_SMMS=1;BS_RENEWAL_SNNM=7;BS_RENEWAL_SEXN={};		BS_RENEWAL_SNSM={cd-e-fg-a-b-};	BS_RENEWAL_MS={Locrian};}
 Default{BS_SCALE_MEMORY(100);BS_RENEWAL_SLAG=0,0,0,0,0,0,0;	BS_RENEWAL_SMMS=0;BS_RENEWAL_SNNM=7;BS_RENEWAL_SEXN={};		BS_RENEWAL_SNSM={cdefgab};		BS_RENEWAL_MS={Ionian(Major)};}
}BS_RENEWAL(0);}
Function BS_HMINOR(Int BS_I){Switch(BS_I){	//ハーモニックマイナースケールへ
Case(00){BS_SCALE_MEMORY(200);BS_RENEWAL_SLAG=-1,0,0,0,-1,0,0;	BS_RENEWAL_SMMS=1;BS_RENEWAL_SNNM=7;BS_RENEWAL_SEXN={};		BS_RENEWAL_SNSM={cde-fga-b};		BS_RENEWAL_MS={Harmonic Minor};}
Case(01){BS_SCALE_MEMORY(201);BS_RENEWAL_SLAG=0,-1,0,-1,-1,0,-1;	BS_RENEWAL_SMMS=1;BS_RENEWAL_SNNM=7;BS_RENEWAL_SEXN={};		BS_RENEWAL_SNSM={cd-e-fg-ab-};	BS_RENEWAL_MS={Locrian 6};}
Case(02){BS_SCALE_MEMORY(202);BS_RENEWAL_SLAG=0,0,0,0,0,0,1;	BS_RENEWAL_SMMS=0;BS_RENEWAL_SNNM=7;BS_RENEWAL_SEXN={};		BS_RENEWAL_SNSM={cdefg+ab};		BS_RENEWAL_MS={Ionian #5};}
Case(03){BS_SCALE_MEMORY(203);BS_RENEWAL_SLAG=0,-1,0,0,-1,1,0;	BS_RENEWAL_SMMS=1;BS_RENEWAL_SNNM=7;BS_RENEWAL_SEXN={};		BS_RENEWAL_SNSM={cde-f+gab-};		BS_RENEWAL_MS={Dorian #11};}
Case(04){BS_SCALE_MEMORY(204);BS_RENEWAL_SLAG=-1,-1,0,-1,0,0,0;	BS_RENEWAL_SMMS=1;BS_RENEWAL_SNNM=7;BS_RENEWAL_SEXN={};		BS_RENEWAL_SNSM={cd-efga-b-};		BS_RENEWAL_MS={Harmonic Minor P5th Below};}
Case(05){BS_SCALE_MEMORY(205);BS_RENEWAL_SLAG=0,0,0,1,0,1,0;	BS_RENEWAL_SMMS=0;BS_RENEWAL_SNNM=7;BS_RENEWAL_SEXN={};		BS_RENEWAL_SNSM={cd+ef+gab};		BS_RENEWAL_MS={Lydian #9};}
Case(06){BS_SCALE_MEMORY(206);BS_RENEWAL_SLAG=-1,-2,0,-1,-1,-1,-1;BS_RENEWAL_SMMS=1;BS_RENEWAL_SNNM=7;BS_RENEWAL_SEXN={};		BS_RENEWAL_SNSM={cd-e-eg-a-a};	BS_RENEWAL_MS={Altered b7};}
 Default{BS_SCALE_MEMORY(200);BS_RENEWAL_SLAG=-1,0, 0,0,-1,0,0;	BS_RENEWAL_SMMS=1;BS_RENEWAL_SNNM=7;BS_RENEWAL_SEXN={};		BS_RENEWAL_SNSM={cde-fga-b};		BS_RENEWAL_MS={Harmonic Minor};}
}BS_RENEWAL(0);}
Function BS_MMINOR(Int BS_I){Switch(BS_I){	//メロディックマイナースケールへ
Case(00){BS_SCALE_MEMORY(300);BS_RENEWAL_SLAG=0,0,0,0,-1,0,0;	BS_RENEWAL_SMMS=1;BS_RENEWAL_SNNM=7;BS_RENEWAL_SEXN={};		BS_RENEWAL_SNSM={cde-fgab};		BS_RENEWAL_MS={Melodic Minor};}
Case(01){BS_SCALE_MEMORY(301);BS_RENEWAL_SLAG=0,-1,0,-1,-1,0,0;	BS_RENEWAL_SMMS=1;BS_RENEWAL_SNNM=7;BS_RENEWAL_SEXN={};		BS_RENEWAL_SNSM={cd-e-fgab-};		BS_RENEWAL_MS={Dorian -9};}
Case(02){BS_SCALE_MEMORY(302);BS_RENEWAL_SLAG=0,0,0,0,0,1,1;	BS_RENEWAL_SMMS=0;BS_RENEWAL_SNNM=7;BS_RENEWAL_SEXN={};		BS_RENEWAL_SNSM={cdef+g+ab};		BS_RENEWAL_MS={Lydian #5};}
Case(03){BS_SCALE_MEMORY(303);BS_RENEWAL_SLAG=0,-1,0,0,0,1,0;	BS_RENEWAL_SMMS=0;BS_RENEWAL_SNNM=7;BS_RENEWAL_SEXN={};		BS_RENEWAL_SNSM={cdef+gab-};		BS_RENEWAL_MS={Mixolydian #11 (Lyd 7)};}
Case(04){BS_SCALE_MEMORY(304);BS_RENEWAL_SLAG=-1,-1,0,0,0,0,0;	BS_RENEWAL_SMMS=0;BS_RENEWAL_SNNM=7;BS_RENEWAL_SEXN={};		BS_RENEWAL_SNSM={cdefga-b-};		BS_RENEWAL_MS={Mixolydian -13};}
Case(05){BS_SCALE_MEMORY(305);BS_RENEWAL_SLAG=-1,-1,0,0,-1,0,-1;	BS_RENEWAL_SMMS=1;BS_RENEWAL_SNNM=7;BS_RENEWAL_SEXN={};		BS_RENEWAL_SNSM={cde-fg-a-b-};	BS_RENEWAL_MS={Aeolian -5 (SLoc)};}
Case(06){BS_SCALE_MEMORY(306);BS_RENEWAL_SLAG=-1,-1,0,-1,-1,-1,-1;BS_RENEWAL_SMMS=1;BS_RENEWAL_SNNM=7;BS_RENEWAL_SEXN={};		BS_RENEWAL_SNSM={cd-e-eg-a-b-};	BS_RENEWAL_MS={Altered};}
 Default{BS_SCALE_MEMORY(300);BS_RENEWAL_SLAG=0,0,0,0,-1,0,0;	BS_RENEWAL_SMMS=1;BS_RENEWAL_SNNM=7;BS_RENEWAL_SEXN={};		BS_RENEWAL_SNSM={cde-fgab};		BS_RENEWAL_MS={Melodic Minor};}
}BS_RENEWAL(0);}
Function BS_OTHER(Int BS_I){Switch(BS_I){	//特殊なスケールへ
Case(00){BS_SCALE_MEMORY(400);BS_RENEWAL_SLAG=3,3,0,0,0,2,2;	BS_RENEWAL_SMMS=0;BS_RENEWAL_SNNM=5;BS_RENEWAL_SEXN={};		BS_RENEWAL_SNSM={cdega};		BS_RENEWAL_MS={Pentatonic};}
Case(01){BS_SCALE_MEMORY(401);BS_RENEWAL_SLAG=3,3,0,1,1,2,3;	BS_RENEWAL_SMMS=1;BS_RENEWAL_SNNM=5;BS_RENEWAL_SEXN={};		BS_RENEWAL_SNSM={ce-ff+gb-};		BS_RENEWAL_MS={Pentatonic Minor Blues};}
Case(02){BS_SCALE_MEMORY(402);BS_RENEWAL_SLAG=3,4,0,1,1,2,3;	BS_RENEWAL_SMMS=1;BS_RENEWAL_SNNM=5;BS_RENEWAL_SEXN={};		BS_RENEWAL_SNSM={ce-fgb-};		BS_RENEWAL_MS={Bluenote Pentatonic};}
Case(03){BS_SCALE_MEMORY(403);BS_RENEWAL_SLAG=0,-1,0,0,-1,0,-1;	BS_RENEWAL_SMMS=1;BS_RENEWAL_SNNM=7;BS_RENEWAL_SEXN={};		BS_RENEWAL_SNSM={cde-ff+ab-};		BS_RENEWAL_MS={Bluenote -3,-7};}
Case(04){BS_SCALE_MEMORY(404);BS_RENEWAL_SLAG=-2,-2,0,-1,-1,-1,-1;BS_RENEWAL_SMMS=1;BS_RENEWAL_SNNM=8;BS_RENEWAL_SEXN={c--|b+};	BS_RENEWAL_SNSM={cd-e-eg-ga|b-};	BS_RENEWAL_MS={Combination Diminish};}
Case(05){BS_SCALE_MEMORY(405);BS_RENEWAL_SLAG=1,1,0,0,0,1,1;	BS_RENEWAL_SMMS=0;BS_RENEWAL_SNNM=6;BS_RENEWAL_SEXN={};		BS_RENEWAL_SNSM={cdef+g+a+};		BS_RENEWAL_MS={Wholetone Scale};}
Case(06){BS_SCALE_MEMORY(406);BS_RENEWAL_SLAG=-1,-2,0,0,-1,0,-1;	BS_RENEWAL_SMMS=1;BS_RENEWAL_SNNM=8;BS_RENEWAL_SEXN={c-|b++};	BS_RENEWAL_SNSM={cde-fg-a-a|b};	BS_RENEWAL_MS={Diminish Scale};}
Case(07){BS_SCALE_MEMORY(407);BS_RENEWAL_SLAG=-1,0,0,0,0,0,0;	BS_RENEWAL_SMMS=0;BS_RENEWAL_SNNM=7;BS_RENEWAL_SEXN={};		BS_RENEWAL_SNSM={cdefga-b};		BS_RENEWAL_MS={Harmonic Major};}
 Default{BS_SCALE_MEMORY(100);BS_RENEWAL_SLAG=0,0,0,0,0,0,0;	BS_RENEWAL_SMMS=0;BS_RENEWAL_SNNM=7;BS_RENEWAL_SEXN={};		BS_RENEWAL_SNSM={cdefgab};		BS_RENEWAL_MS={Ionian(Major)};}
}BS_RENEWAL(0);}
Function BS_WORLD(Int BS_I){Switch(BS_I){	//民族スケールへ
Case(00){BS_SCALE_MEMORY(500);BS_RENEWAL_SLAG=3,3,0,0,1,2,2;	BS_RENEWAL_SMMS=0;BS_RENEWAL_SNNM=5;BS_RENEWAL_SEXN={};		BS_RENEWAL_SNSM={cdfga};		BS_RENEWAL_MS={"律旋法1"};}
Case(01){BS_SCALE_MEMORY(501);BS_RENEWAL_SLAG=0,-1,0,0,-1,0,0;	BS_RENEWAL_SMMS=1;BS_RENEWAL_SNNM=7;BS_RENEWAL_SEXN={};		BS_RENEWAL_SNSM={cde-fgab-};		BS_RENEWAL_MS={"律旋法2"};}
Case(02){BS_SCALE_MEMORY(502);BS_RENEWAL_SLAG=3,3,0,0,0,2,2;	BS_RENEWAL_SMMS=0;BS_RENEWAL_SNNM=5;BS_RENEWAL_SEXN={};		BS_RENEWAL_SNSM={cdega};		BS_RENEWAL_MS={"呂旋法1"};}
Case(03){BS_SCALE_MEMORY(503);BS_RENEWAL_SLAG=0,0,0,0,0,1,0;	BS_RENEWAL_SMMS=0;BS_RENEWAL_SNNM=7;BS_RENEWAL_SEXN={};		BS_RENEWAL_SNSM={cdef+gab};		BS_RENEWAL_MS={"呂旋法2"};}
Case(04){BS_SCALE_MEMORY(504);BS_RENEWAL_SLAG=3,2,0,-1,1,2,3;	BS_RENEWAL_SMMS=0;BS_RENEWAL_SNNM=5;BS_RENEWAL_SEXN={};		BS_RENEWAL_SNSM={cd-fga+};		BS_RENEWAL_MS={"陰旋法(上行形)"};}
Case(05){BS_SCALE_MEMORY(505);BS_RENEWAL_SLAG=3,3,0,-1,1,2,1;	BS_RENEWAL_SMMS=0;BS_RENEWAL_SNNM=5;BS_RENEWAL_SEXN={};		BS_RENEWAL_SNSM={cd-fga-};		BS_RENEWAL_MS={"陰旋法(下行形)"};}
Case(06){BS_SCALE_MEMORY(506);BS_RENEWAL_SLAG=3,3,0,0,1,2,3;	BS_RENEWAL_SMMS=0;BS_RENEWAL_SNNM=5;BS_RENEWAL_SEXN={};		BS_RENEWAL_SNSM={cdfga+};		BS_RENEWAL_MS={"陽旋法(上行形)"};}
Case(07){BS_SCALE_MEMORY(507);BS_RENEWAL_SLAG=3,3,0,0,1,2,1;	BS_RENEWAL_SMMS=0;BS_RENEWAL_SNNM=5;BS_RENEWAL_SEXN={};		BS_RENEWAL_SNSM={cdfga};		BS_RENEWAL_MS={"陽旋法(下行形)"};}
Case(08){BS_SCALE_MEMORY(508);BS_RENEWAL_SLAG=3,2,0,-1,-1,2,1;	BS_RENEWAL_SMMS=1;BS_RENEWAL_SNNM=5;BS_RENEWAL_SEXN={};		BS_RENEWAL_SNSM={cd-e-ga-};		BS_RENEWAL_MS={"バリスケール"};}
Case(09){BS_SCALE_MEMORY(509);BS_RENEWAL_SLAG=3,2,0,-1,-1,0,1;	BS_RENEWAL_SMMS=1;BS_RENEWAL_SNNM=5;BS_RENEWAL_SEXN={};		BS_RENEWAL_SNSM={cd-e-fa-};		BS_RENEWAL_MS={"ジャワスケール"};}
Case(10){BS_SCALE_MEMORY(510);BS_RENEWAL_SLAG=-2,-3,0,-1,-1,-1,-2;BS_RENEWAL_SMMS=1;BS_RENEWAL_SNNM=8;BS_RENEWAL_SEXN={c--|b++};	BS_RENEWAL_SNSM={cd-e-efga-|b-};	BS_RENEWAL_MS={"スパニッシュスケール"};}
Case(11){BS_SCALE_MEMORY(511);BS_RENEWAL_SLAG=-1,0,0,-1,0,0,0;	BS_RENEWAL_SMMS=0;BS_RENEWAL_SNNM=7;BS_RENEWAL_SEXN={};		BS_RENEWAL_SNSM={cd-efga-b};		BS_RENEWAL_MS={"ペルシャンスケール"};}
Case(12){BS_SCALE_MEMORY(512);BS_RENEWAL_SLAG=-1,0,0,0,-1,1,0;	BS_RENEWAL_SMMS=1;BS_RENEWAL_SNNM=7;BS_RENEWAL_SEXN={};		BS_RENEWAL_SNSM={cde-f+ga-b};		BS_RENEWAL_MS={"ハンガリアンスケール"};}
Case(13){BS_SCALE_MEMORY(513);BS_RENEWAL_SLAG=1,0,0,1,0,1,1;	BS_RENEWAL_SMMS=1;BS_RENEWAL_SNNM=7;BS_RENEWAL_SEXN={};		BS_RENEWAL_SNSM={cd+ef+g+a+b};	BS_RENEWAL_MS={"エニグマチックスケール"};}
Case(14){BS_SCALE_MEMORY(514);BS_RENEWAL_SLAG=0,0,0,-1,-1,0,0;	BS_RENEWAL_SMMS=0;BS_RENEWAL_SNNM=7;BS_RENEWAL_SEXN={};		BS_RENEWAL_SNSM={cd-e-fgab};		BS_RENEWAL_MS={"ナポリタンスケール"};}
Case(15){BS_SCALE_MEMORY(515);BS_RENEWAL_SLAG=-1,-1,0,0,0,0,0;	BS_RENEWAL_SMMS=1;BS_RENEWAL_SNNM=7;BS_RENEWAL_SEXN={};		BS_RENEWAL_SNSM={cdefga-b-};		BS_RENEWAL_MS={"ヒンズースケール1"};}
Case(16){BS_SCALE_MEMORY(516);BS_RENEWAL_SLAG=0,-1,0,-1,-1,0,0;	BS_RENEWAL_SMMS=1;BS_RENEWAL_SNNM=7;BS_RENEWAL_SEXN={};		BS_RENEWAL_SNSM={cd-e-fgab-};		BS_RENEWAL_MS={"ヒンズースケール2"};}
Case(17){BS_SCALE_MEMORY(517);BS_RENEWAL_SLAG=-1,0,0,0,-1,1,0;	BS_RENEWAL_SMMS=1;BS_RENEWAL_SNNM=7;BS_RENEWAL_SEXN={};		BS_RENEWAL_SNSM={cde-f+ga-b};		BS_RENEWAL_MS={"ジプシースケール"};}
Case(18){BS_SCALE_MEMORY(518);BS_RENEWAL_SLAG=3,2,0,-1,-1,2,1;	BS_RENEWAL_SMMS=1;BS_RENEWAL_SNNM=5;BS_RENEWAL_SEXN={};		BS_RENEWAL_SNSM={cd-e-ga-};		BS_RENEWAL_MS={"ペログスケール"};}
Case(19){BS_SCALE_MEMORY(519);BS_RENEWAL_SLAG=3,3,0,0,0,2,2;;	BS_RENEWAL_SMMS=0;BS_RENEWAL_SNNM=5;BS_RENEWAL_SEXN={};		BS_RENEWAL_SNSM={cdega};		BS_RENEWAL_MS={"スレンドロスケール"};}
Case(20){BS_SCALE_MEMORY(520);BS_RENEWAL_SLAG=-2,-2,0,-1,-1,-1,-1;BS_RENEWAL_SMMS=1;BS_RENEWAL_SNNM=8;BS_RENEWAL_SEXN={c--|b+};	BS_RENEWAL_SNSM={cd-e-ef+ga|b-};	BS_RENEWAL_MS={"メシアン"};}
Case(21){BS_SCALE_MEMORY(521);BS_RENEWAL_SLAG=0,-1,0,0,-1,1,0;	BS_RENEWAL_SMMS=1;BS_RENEWAL_SNNM=7;BS_RENEWAL_SEXN={};		BS_RENEWAL_SNSM={cde-f+gab-};		BS_RENEWAL_MS={"アラブ(マカーム・ヒジャーズ)"};}
Case(22){BS_SCALE_MEMORY(522);BS_RENEWAL_SLAG=-1,-1,0,-1,-1,0,0;	BS_RENEWAL_SMMS=1;BS_RENEWAL_SNNM=7;BS_RENEWAL_SEXN={};		BS_RENEWAL_SNSM={cd-e-fga-b-};	BS_RENEWAL_MS={"インド(ラーガ・バイラヴィ)"};}
Case(23){BS_SCALE_MEMORY(523);BS_RENEWAL_SLAG=0,0,0,-1,-1,1,0;	BS_RENEWAL_SMMS=1;BS_RENEWAL_SNNM=7;BS_RENEWAL_SEXN={};		BS_RENEWAL_SNSM={cd-e-f+ga-b};	BS_RENEWAL_MS={"インド(ラーガ・トーディ)"};}
Case(24){BS_SCALE_MEMORY(524);BS_RENEWAL_SLAG=0,0,0,-1,0,1,0;	BS_RENEWAL_SMMS=0;BS_RENEWAL_SNNM=7;BS_RENEWAL_SEXN={};		BS_RENEWAL_SNSM={cd-ef+gab};		BS_RENEWAL_MS={"インド(ラーガ・マルワ)"};}
Case(25){BS_SCALE_MEMORY(525);BS_RENEWAL_SLAG=3,3,0,0,1,2,3;	BS_RENEWAL_SMMS=1;BS_RENEWAL_SNNM=5;BS_RENEWAL_SEXN={};		BS_RENEWAL_SNSM={cdfgb-};		BS_RENEWAL_MS={"エジプトスケール"};}
Case(26){BS_SCALE_MEMORY(526);BS_RENEWAL_SLAG=3,5,0,2,1,2,4;	BS_RENEWAL_SMMS=0;BS_RENEWAL_SNNM=5;BS_RENEWAL_SEXN={};		BS_RENEWAL_SNSM={cefgb};		BS_RENEWAL_MS={"沖縄スケール"};}
Case(27){BS_SCALE_MEMORY(527);BS_RENEWAL_SLAG=5,4,2,1,3,4,3;	BS_RENEWAL_SMMS=1;BS_RENEWAL_SNNM=5;BS_RENEWAL_SEXN={};		BS_RENEWAL_SNSM={de-gab-};		BS_RENEWAL_MS={"演歌"};}
 Default{BS_SCALE_MEMORY(100);BS_RENEWAL_SLAG=0,0,0,0,0,0,0;	BS_RENEWAL_SMMS=0;BS_RENEWAL_SNNM=7;BS_RENEWAL_SEXN={};		BS_RENEWAL_SNSM={cdefgab};		BS_RENEWAL_MS={"Ionian(Major)"};}
}BS_RENEWAL(0);}

Function BS_SCALE_b1(){		BS_RENEWAL_SPBE(2)=BS_RENEWAL_SPBE(2)-1;BS_RENEWAL(1);}	//1stを１半音下へ
Function BS_SCALE_b2(){		BS_RENEWAL_SPBE(3)=BS_RENEWAL_SPBE(3)-1;BS_RENEWAL(1);}	//2nd(=9th)を１半音下へ
Function BS_SCALE_b3(){		BS_RENEWAL_SPBE(4)=BS_RENEWAL_SPBE(4)-1;BS_RENEWAL(1);}	//3rdを１半音下へ
Function BS_SCALE_b4(){		BS_RENEWAL_SPBE(5)=BS_RENEWAL_SPBE(5)-1;BS_RENEWAL(1);}	//4th(=11th)を１半音下へ
Function BS_SCALE_b5(){		BS_RENEWAL_SPBE(6)=BS_RENEWAL_SPBE(6)-1;BS_RENEWAL(1);}	//5thを１半音下へ
Function BS_SCALE_b6(){		BS_RENEWAL_SPBE(0)=BS_RENEWAL_SPBE(0)-1;BS_RENEWAL(1);}	//6th(=13th)を１半音下へ
Function BS_SCALE_b7(){		BS_RENEWAL_SPBE(1)=BS_RENEWAL_SPBE(1)-1;BS_RENEWAL(1);}	//7thを１半音下へ
Function BS_SCALE_b9(){		BS_RENEWAL_SPBE(3)=BS_RENEWAL_SPBE(3)-1;BS_RENEWAL(1);}	//9th(=2rd)を１半音下へ
Function BS_SCALE_b11(){	BS_RENEWAL_SPBE(5)=BS_RENEWAL_SPBE(5)-1;BS_RENEWAL(1);}	//11th(=4th)を１半音下へ
Function BS_SCALE_b13(){	BS_RENEWAL_SPBE(0)=BS_RENEWAL_SPBE(0)-1;BS_RENEWAL(1);}	//13th(=6th)を１半音下へ
Function BS_SCALE_p1(){		BS_RENEWAL_SPBE(2)=BS_RENEWAL_SPBE(2)+1;BS_RENEWAL(1);}	//1stを１半音上へ
Function BS_SCALE_p2(){		BS_RENEWAL_SPBE(3)=BS_RENEWAL_SPBE(3)+1;BS_RENEWAL(1);}	//2nd(=9th)を１半音上へ
Function BS_SCALE_p3(){		BS_RENEWAL_SPBE(4)=BS_RENEWAL_SPBE(4)+1;BS_RENEWAL(1);}	//3rdを１半音上へ
Function BS_SCALE_p4(){		BS_RENEWAL_SPBE(5)=BS_RENEWAL_SPBE(5)+1;BS_RENEWAL(1);}	//4th(=11th)を１半音上へ
Function BS_SCALE_p5(){		BS_RENEWAL_SPBE(6)=BS_RENEWAL_SPBE(6)+1;BS_RENEWAL(1);}	//5thを１半音上へ
Function BS_SCALE_p6(){		BS_RENEWAL_SPBE(0)=BS_RENEWAL_SPBE(0)+1;BS_RENEWAL(1);}	//6th(=13th)を１半音上へ
Function BS_SCALE_p7(){		BS_RENEWAL_SPBE(1)=BS_RENEWAL_SPBE(1)+1;BS_RENEWAL(1);}	//7thを１半音上へ
Function BS_SCALE_p9(){		BS_RENEWAL_SPBE(3)=BS_RENEWAL_SPBE(3)+1;BS_RENEWAL(1);}	//9th(=2rd)を１半音上へ
Function BS_SCALE_p11(){	BS_RENEWAL_SPBE(5)=BS_RENEWAL_SPBE(5)+1;BS_RENEWAL(1);}	//11th(=4th)を１半音上へ
Function BS_SCALE_p13(){	BS_RENEWAL_SPBE(0)=BS_RENEWAL_SPBE(0)+1;BS_RENEWAL(1);}	//13th(=6th)を１半音上へ

Function BS_SCALE_MAJOR(){			BS_MODE(0);}	//Major Scale(cdefgab)(CM7)
Function BS_SCALE_MINOR(){			BS_MODE(5);}	//Minor Scale(cde-fga-b-)(Am7)

Function BS_SCALE_IONIAN(){			BS_MODE(0);}	//Ionian (cdefgab)(CM7)
Function BS_SCALE_DORIAN(){			BS_MODE(1);}	//Dorian (cde-fgab-)(Dm7)
Function BS_SCALE_PHRYGIAN(){			BS_MODE(2);}	//Phrygian (cd-e-fga-b-)(Em7)
Function BS_SCALE_LYDIAN(){			BS_MODE(3);}	//Lydian (cdef+gab)(FM7)
Function BS_SCALE_MIXOLYDIAN(){		BS_MODE(4);}	//Mixolydian (cdefgab-)(G7)
Function BS_SCALE_AEOLIAN(){			BS_MODE(5);}	//Aeolian (cde-fga-b-)(Am7)
Function BS_SCALE_LOCRIAN(){			BS_MODE(6);}	//Locrian (cd-e-fg-a-b-)(Bm7b5)

Function BS_SCALE_HMINOR(){				BS_HMINOR(0);}	//Harmonic Minor (cde-fga-b)(Cm7)
Function BS_SCALE_LOCRIAN_6(){			BS_HMINOR(1);}	//Locrian 6 (cd-e-fg-ab-)(Dm7b5)
Function BS_SCALE_LOCRIAN_13(){			BS_HMINOR(1);}	//Locrian 13 (cd-e-fg-ab-)(Dm7b5)
Function BS_SCALE_IONIAN_p5(){			BS_HMINOR(2);}	//Ionian #5 (cdefg+ab)(EbM7#5)
Function BS_SCALE_IONIANAUGEMENTED(){		BS_HMINOR(2);}	//Ionian Augemented (cdefg+ab)(EbM7#5)
Function BS_SCALE_DORIAN_p11(){			BS_HMINOR(3);}	//Dorian #11 (cde-f+gab-)(Fm7)
Function BS_SCALE_HMINORP5B(){			BS_HMINOR(4);}	//Harmonic Minor Perfect 5th Below (cd-efga-b-)(G7)
Function BS_SCALE_HMINORPERFECT5THBELOW(){	BS_HMINOR(4);}	//Harmonic Minor Perfect 5th Below (cd-efga-b-)(G7)
Function BS_SCALE_LYDIAN_p9(){			BS_HMINOR(5);}	//Lydian #9 (cd+ef+gab)(AbM7)
Function BS_SCALE_LYDIAN_p2(){			BS_HMINOR(5);}	//Lydian #2 (cd+ef+gab)(AbM7)
Function BS_SCALE_ALTERED_b7(){			BS_HMINOR(6);}	//Altered b7 (cd-e-eg-a-a)(Bdim)

Function BS_SCALE_MMINOR(){			BS_MMINOR(0);}	//Melodic Minor (cde-fgab)(Cm7)
Function BS_SCALE_DORIAN_b9(){		BS_MMINOR(1);}	//Dorian -9 (cd-e-fgab-)(Dm7)
Function BS_SCALE_DORIAN_b2(){		BS_MMINOR(1);}	//Dorian -2 (cd-e-fgab-)(Dm7)
Function BS_SCALE_LYDIAN_p5(){		BS_MMINOR(2);}	//Lydian #5 (cdef+g+ab)(EbM7#5)
Function BS_SCALE_LYDIANAUGEMENTED(){	BS_MMINOR(2);}	//Lydian Augemented (cdef+g+ab)(EbM7#5)
Function BS_SCALE_MIXOLYDIAN_p11(){		BS_MMINOR(3);}	//Mixolydian #11 (cdef+gab-)(F7)
Function BS_SCALE_LYDIAN_b7(){		BS_MMINOR(3);}	//Lydian -7 (cdef+gab-)(F7)
Function BS_SCALE_MIXOLYDIAN_b6(){		BS_MMINOR(4);}	//Mixolydian -6 (cdefga-b-)(G7)
Function BS_SCALE_MIXOLYDIAN_b13(){		BS_MMINOR(4);}	//Mixolydian -13 (cdefga-b-)(G7)
Function BS_SCALE_AEOLIAN_b5(){		BS_MMINOR(5);}	//Aeolian -5 (cde-fg-a-b-)(Abm7b5)
Function BS_SCALE_SUPERLOCRIAN(){		BS_MMINOR(5);}	//Super Locrian (cde-fg-a-b-)(Abm7b5)
Function BS_SCALE_LOCRIAN_2(){		BS_MMINOR(5);}	//Locrian 2 (cde-fg-a-b-)(Abm7b5)
Function BS_SCALE_ALTERED(){			BS_MMINOR(6);}	//Altered (cd-e-eg-a-b-)(B7)
Function BS_SCALE_ALTEREDDOMINANT(){	BS_MMINOR(6);}	//Altered Dominant (cd-e-eg-a-b-)(B7)
//----------------------------------------------------------------------------------------------
//	End Of bwb_scale.h
//----------------------------------------------------------------------------------------------
