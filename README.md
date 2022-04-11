# What is str library?
目前STR仅供个人使用，为后期开发私人服务器做铺垫。这是一个动态分配内存的c语言字符串处理库。

# 最新更新
加入了版本号，之后其他程序调用str库写程序时，需要著名版本号 _STR_VERSION
目前最新的版本号是1.0
1.0版本之前的所有版本为版本0.9
新版本号需要注意对旧版本提供接口支持

# 函数接口
定义版本号
```c
    #define _STR_VERSION 1.0
```
传入一个指针，释放内存，该函数会检测指针值，所以传入NULL指针也是安全的。
最后所有的指针将会被赋值NULL。无法处理NULL
```c
	void free_str(str_p p);
```
根据传入的常字符串创建一个str字符串，如果失败会返回NULL，就算传入的字符串是空的，也会创建一个size为1的字符串，该字符串就是\0。
```c
    str_p new_str(const char* string);
```
根据传入的指针来拷贝一个字符串，**硬拷贝**，**无法处理传入的NULL指针**
```c
    str_p cpy_str(const str_p p);
```
返回buff的尺寸，本质是strlen，**无法处理NULL指针**
```c
    size_t sizeof_buff(const char* string);
```
创建一个全零的字符串，如果创建失败，返回NULL。如果用户输出的size是0那么不会报错，但是错误不可追踪。如果size是负数则系统抛出异常
```c
    str_p zero_str(size_t size);
```
生成一个新的字符串，该字符串内容会倒置，无法处理NULL
```c
    str_p revs_str(const str_p p);
```
重写一个字符串，会覆盖，由于调用freestr，所以无法处理null
```c
    str_p overwrite_str(str_p p, const char* string);
```
交换两个字符串，单纯进行地址交换，所以不检测内容，仅仅将指向的地址交换
```c
    void swp_str(str_p p, str_p q);
```
检测两个字符串是否相同，不检测size的值，仅仅检测buffer的值，本质相当于strcmp，无法处理null
```c
    int cmp_str(const str_p p, const str_p q);
```
    本质是strcmp，但是直接针对buffer，功能与cmp_str相同
```c
    int cmp_charArray_(const char* p1, const char* p2);
```
相信传入的file指针，将文件中的数据全部读取到内存中
```c
    str_p readin_file_str(FILE* fp);
```
相信传入的file指针，将字符串内容全部写入文件中（当前位置）
```c
    int write2_file_str(FILE* fp, const str_p p);
```
对字符串进行排序，算法是快速排序，无法检测null，会更改字符串的内容
```c
    str_p nsort_str(str_p p, size_t low, size_t high);
```
对字符串进行排序，算法是快速排序，无法检测null，默认low是第一位，high是size，会更改字符串的内容
```c
    str_p sort_str(str_p p);
```
根据buffer的真是尺寸更新size的值，但是经常有bug，其中之一的bug考虑它检测长度可能使用strlen，所以要找0
```c
    size_t chk_str(str_p p);
```
后面接一个常字符串生成一个新的字符串，且旧字符串不会被摧毁
```c
    str_p append_str(str_p p, const char* string);
```
交换字符串内部两个位置的字符
```c
    str_p swap_chr(str_p p, unsigned long index1, unsigned long index2);
```
```c
本质是memcmp
    int memcmp_str(const char* s1, const char* s2, size_t n);
```
配合quickSort函数进行快排
```c
    size_t partition(char* arr, size_t low, size_t high);
```
被sort调用的快排函数
```c
    void quickSort(char* arr, size_t low, size_t high);
```





# 新版本更新
单纯返回size的value，已经被删除
```c
    size_t size_str(const str_p p);
```