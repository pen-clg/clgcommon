/*=========================================================
	
	CLGerrno.h
	
	ClassGエラーコード
	
=========================================================*/
#ifndef CLG_ERRNO_H
#define CLG_ERRNO_H

/*-----------------------------------------------
	成功
-----------------------------------------------*/
#define CLG_ERROR_OK 0
#define CLG_OK       CLG_ERROR_OK

/*-----------------------------------------------
	エラーマクロ
-----------------------------------------------*/
/* 成功したか調べる */
#define is_ok( err ) ( ( err ) >= CLG_OK )

/* エラーかどうか調べる */
#define is_error( err ) ( ( err ) < CLG_OK )

/* エラーコードがSCE APIからのエラーかどうか調べる */
#define is_sce_error( err ) ( (( err ) & 0xF0000000 ) == 0x80000000 )

/* エラーがCLGERRNOであるか調べる */
#define is_clg_error( err )  ( (( err ) & 0xF0000000 ) == 0xE0000000 )

/* 各種ライブラリが返す*UID、およびSCEのAPIが返すSceUIDがが有効な値かどうか調べる */
#define is_valid_uid( uid ) ( (int)( uid ) > CLG_OK )

/*-----------------------------------------------
	汎用エラー
-----------------------------------------------*/
/* 何らかのエラー */
#define CLG_ERROR_UNKNOWN                 0xE001FFFF

/* 不正な引数 */
#define CLG_ERROR_INVALID_ARGUMENT        0xE0010001

/* メモリが不足している */
#define CLG_ERROR_NOT_ENOUGH_MEMORY       0xE0010002

/* バッファが不足している */
#define CLG_ERROR_OUT_OF_BUFFER           0xE0010003

/* 許可されていない操作を行った */
#define CLG_ERROR_OPERATION_NOT_PERMITTED 0xE0010004

/* 存在していない */
#define CLG_ERROR_NOT_FOUND               0xE0010005

/* 存在している */
#define CLG_ERROR_ALREADY_EXIST           0xE0010006

/* 読み込み禁止 */
#define CLG_ERROR_NOT_READABLE            0xE0010009

/* 書き込み禁止 */
#define CLG_ERROR_NOT_WRITABLE            0xE001000A

/* ディレクトリである */
#define CLG_ERROR_IS_DIRECTORY            0xE001000B

/* ディレクトリではない */
#define CLG_ERROR_NOT_DIRECTORY           0xE001000C

/* 既に実行されている */
#define CLG_ERROR_ALREADY_RUNNING         0xE001000D

/* まだ実行されていない */
#define CLG_ERROR_NOT_RUNNING_YET         0xE001000E

/* 既に初期化されている */
#define CLG_ERROR_ALREADY_INITIALIZED     0xE001000F

/* まだ初期化されていない */
#define CLG_ERROR_NOT_INITIALIZED_YET     0xE0010010

/* 既に開いている */
#define CLG_ERROR_ALREADY_OPENED          0xE0010011

/* まだ開いていない */
#define CLG_ERROR_NOT_OPENED_YET          0xE0010012

/* 機能は未実装 */
#define CLG_ERROR_NOT_IMPLEMENTED_YET     0xE0010013

/* 不正なパラメータ */
#define CLG_ERROR_INVALID_PARAM           0xE0010014


/* シグネチャが一致しない */
#define CLG_ERROR_SIGNATURE_MISMATCH      0xE0030001

/* サポートしていないバージョン */
#define CLG_ERROR_NOT_SUPPORTED           0xE0030002
	
/* 指定されたセクションは存在しない */
#define CLG_ERROR_SECTION_NOT_FOUND       0xE0030003

/* 指定されたキーは存在しない */
#define CLG_ERROR_KEY_NOT_FOUND           0xE0030004

/* 指定されたデータは存在しない */
#define CLG_ERROR_DATA_NOT_FOUND          0xE0030005

/* 型が適合していない */
#define CLG_ERROR_TYPE_MISMATCH           0xE0030006


/*-----------------------------------------------
	SCE API エラー
-----------------------------------------------*/
#define CLG_ERROR_FAILED_TO_CREATE_SEMA 0xE0FF0001
#define CLG_ERROR_FAILED_TO_GETSTAT     0xE0FF0002
#define CLG_ERROR_FAILED_TO_OPEN        0xE0FF0004
#define CLG_ERROR_FAILED_TO_READ        0xE0FF0005
#define CLG_ERROR_FAILED_TO_WRITE       0xE0FF0006
#define CLG_ERROR_FAILED_TO_SEEK        0xE0FF0007
#define CLG_ERROR_FAILED_TO_DOPEN       0xE0FF0009
#define CLG_ERROR_FAILED_TO_DREAD       0xE0FF000A

#endif
