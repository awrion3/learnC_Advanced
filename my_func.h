#ifndef __MY_FUNC_H__
#define __MY_FUNC_H__ //���ǵǾ� ���������� ������

//��ó���� 
#pragma warning(disable:4996)

//�����Ϸ� �������
#include <stdio.h>
#include <stdlib.h> //�����Ҵ� ����
#include <string.h> //���ڿ� ó�� ����

//����� �������
#include "my_struct.h"	//����ü ���� ����
#include "my_define.h"	//����� ������ ����

//�Լ� ���� ����
void menu(void);				    //�޴�
int reg_insert(TEL**, int, int);    //���
void show_all(TEL**, int);			//����
int delete_tel(TEL**, int);			//����
void find_by_birth(TEL**, int);		//�˻�
int reg_from_file(TEL**, int, int);	//����

#endif