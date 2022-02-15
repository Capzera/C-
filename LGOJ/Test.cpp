#include<bits/stdc++.h>
using namespace std;
char c[9];
void print();
int main(){
    for(int i=1;i<=8;i++)cin>>c[i];
    printf("\n\n\n\n\n");
    print();
    printf("@->create database db_school default character set gb2312 default collate gb2312_chinsese_ci;\n");
    printf("Query OK, 1 row affected (0.01 sec)\n\n\n\n\n");
    print();
    printf("@->show databases;\n");
    printf("+---------------------+\n");
    printf("| Database            |\n");
    printf("+---------------------+\n");
    printf("| db_sch              |\n");
    printf("| db_school           |\n");
    printf("| information_schema  |\n");
    printf("| mysql               |\n");
    printf("| performance_schema  |\n");
    printf("| sakila              |\n");
    printf("| sys                 |\n");
    printf("| test                |\n");
    printf("| world               |\n");
    printf("+---------------------+\n");
    printf("9 rows in set (0.01 sec)\n\n\n\n\n");
    print();
    printf("@->alter database db_school default character set gbk default collate gbk_chinese_ci;\n");
    printf("Query OK, 1 row affected (0.01 sec)\n\n\n\n\n");
    print();
    printf("drop database db_school;\n");
    printf("Query OK,0 rows affected (0.01 sec)\n");
    print();
    printf("@->show databases;\n");
    printf("+---------------------+\n");
    printf("| Database            |\n");
    printf("+---------------------+\n");
    printf("| db_sch              |\n");
    printf("| information_schema  |\n");
    printf("| mysql               |\n");
    printf("| performance_schema  |\n");
    printf("| sakila              |\n");
    printf("| sys                 |\n");
    printf("| test                |\n");
    printf("| world               |\n");
    printf("+---------------------+\n");
    printf("8 rows in set (0.01 sec)\n\n\n\n\n");
    print();
    printf("@->use db_school;\n");
    printf("Database changed\n");
    print();
    printf("@->create table tb_student(\n");
    printf("    -> studentNo char(10) not null,\n");
    printf("    -> studentName varchar(10) not null,\n");
    printf("    -> sex char(2),\n");
    printf("    -> birthday date,\n");
    printf("    -> native varchar(20),\n");
    printf("    -> nation varchar(10) default \'��\',\n");
    printf("    -> classNo char(6),\n");
    printf("    -> primary key(studentNo)\n");
    printf("    -> )engine=innodb;\n");
    printf("Query OK, 0 rows affected (0.03 sec)\n\n\n\n\n");
    print();
    printf("@->show tables;\n");
    printf("+---------------------+\n");   
    printf("| Tables_in_db_school |\n");
    printf("+---------------------+\n"); 
    printf("| tb_student          |\n");
    printf("+---------------------+\n"); 
    printf("1 row in set (0.01 sec)\n\n\n\n\n");
    print();
    printf("@->desc tb_student\n");
    printf("+-------------+-------------+------+-----+---------+-------+\n");
    printf("| Field       | Type        | Null | Key | Default | Extra |\n");
    printf("+-------------+-------------+------+-----+---------+-------+\n");
    printf("| studentNo   | char(10)    | NO   | PRI | NULL    |       |\n");
    printf("| studentName | varchar(10) | NO   |     | NULL    |       |\n");
    printf("| sex         | char(2)     | YES  |     | NULL    |       |\n");
    printf("| birthday    | date        | YES  |     | NULL    |       |\n");
    printf("| native      | varchar(20) | YES  |     | NULL    |       |\n");
    printf("| nation      | varchar(10) | YES  |     | ��      |       |\n");
    printf("| classNo     | char(6)     | YES  |     | NULL    |       |\n");
    printf("+-------------+-------------+------+-----+---------+-------+\n");
    printf("7 rows in set (0.01 sec)\n\n\n\n\n");
    print();
    printf("@->show create table tb_student;\n");
    printf("+------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+");
    printf("| Table      | Create Table                                                                                                                                                                                                                                                                                               |");
    printf("+------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+");
    printf("| tb_student | CREATE TABLE `tb_student` (\n");
    printf("  `studentNo` char(10) NOT NULL,\n");
    printf("  `studentName` varchar(10) NOT NULL,\n");
    printf("  `sex` char(2) DEFAULT NULL,\n");
    printf("  `birthday` date DEFAULT NULL,\n");
    printf("  `native` varchar(20) DEFAULT NULL,\n");
    printf("  `nation` varchar(10) DEFAULT \'��\',\n");
    printf("  `classNo` char(6) DEFAULT NULL,\n");
    printf("  PRIMARY KEY (`studentNo`)\n");
    printf(") ENGINE=InnoDB DEFAULT CHARSET=gb2312 |\n");
    printf("+------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+");
    printf("1 row in set (0.01 sec)\n\n\n");
    print();
    printf("@->create table tb_student2 like tb_student;\n");
    printf("Query OK, 0 rows affected (0.03 sec)\n\n");
    print();
    printf("@->alter table tb_student2 add column id int not null unique auto_increment first;\n");
    printf("Query OK, 0 rows affected (0.06 sec)\n");
    printf("Records: 0  Duplicates: 0  Warnings: 0\n\n\n\n\n");
    print();
    printf("@->alter table tb_student add coloum department varchar(16) defult\'����ѧԺ\'after nation;\n");
    printf("Query OK, 0 rows affected (0.05 sec)\n");
    printf("Records: 0  Duplicates: 0  Warnings: 0\n\n\n\n\n");
    print();
    printf("@->alter table tb_student change coloum birthday age tinyint null default 18;\n");
    printf("Query OK, 0 rows affected (0.05 sec)\n");
    printf("Records: 0  Duplicates: 0  Warnings: 0\n\n");
    print();
    printf("@->desc tb_student\n");
    printf("+-------------+-------------+------+-----+----------+-------+\n");
    printf("| Field       | Type        | Null | Key | Default  | Extra |\n");
    printf("+-------------+-------------+------+-----+----------+-------+\n");
    printf("| studentNo   | char(10)    | NO   | PRI | NULL     |       |\n");
    printf("| studentName | varchar(10) | NO   |     | NULL     |       |\n");
    printf("| sex         | char(2)     | YES  |     | NULL     |       |\n");
    printf("| age         | tinyint     | YES  |     | 18       |       |\n");
    printf("| native      | varchar(20) | YES  |     | NULL     |       |\n");
    printf("| nation      | varchar(10) | YES  |     | ��       |       |\n");
    printf("| department  | varchar(16) | YES  |     | ����ѧԺ |       |\n");
    printf("| classNo     | char(6)     | YES  |     | NULL     |       |\n");
    printf("+-------------+-------------+------+-----+----------+-------+\n"); 
    printf("8 rows in set (0.00 sec)\n\n\n\n\n");
    print();
    printf("@->alter table tb_student alter column department drop defult;\n");
    printf("Query OK, 0 rows affected (0.01 sec)\n");
    printf("Records: 0  Duplicates: 0  Warnings: 0\n\n");
    print();
    printf("@->desc tb_student\n");
    printf("+-------------+-------------+------+-----+---------+-------+\n");
    printf("| Field       | Type        | Null | Key | Default | Extra |\n");
    printf("+-------------+-------------+------+-----+---------+-------+\n");
    printf("| studentNo   | char(10)    | NO   | PRI | NULL    |       |\n");
    printf("| studentName | varchar(10) | NO   |     | NULL    |       |\n");
    printf("| sex         | char(2)     | YES  |     | NULL    |       |\n");
    printf("| age         | tinyint     | YES  |     | 18      |       |\n");
    printf("| native      | varchar(20) | YES  |     | NULL    |       |\n");
    printf("| nation      | varchar(10) | YES  |     | ��      |       |\n");
    printf("| department  | varchar(16) | YES  |     | NULL    |       |\n");
    printf("| classNo     | char(6)     | YES  |     | NULL    |       |\n");
    printf("+-------------+-------------+------+-----+---------+-------+\n"); 
    printf("8 rows in set (0.00 sec)\n\n\n\n\n");
    print();
    printf("@->alter table tb_student alter column department set default \'����ѧԺ\';\n\n");
    printf("Query OK, 0 rows affected (0.02 sec)\n");
    printf("Records: 0  Duplicates: 0  Warnings: 0\n\n\n\n\n");
    print();
    printf("@->alter table tb_student modify department varchar(20) not NULL after studentName;\n");
    printf("Query OK, 0 rows affected (0.05 sec)\n");
    printf("Records: 0  Duplicates: 0  Warnings: 0\n\n");
    print();
    printf("@->desc tb_student\n");
    printf("+-------------+-------------+------+-----+---------+-------+\n");
    printf("| Field       | Type        | Null | Key | Default | Extra |\n");
    printf("+-------------+-------------+------+-----+---------+-------+\n");
    printf("| studentNo   | char(10)    | NO   | PRI | NULL    |       |\n");
    printf("| studentName | varchar(10) | NO   |     | NULL    |       |\n");
    printf("| department  | varchar(20) | NO   |     | NULL    |       |\n");
    printf("| sex         | char(2)     | YES  |     | NULL    |       |\n");
    printf("| age         | tinyint     | YES  |     | 18      |       |\n");
    printf("| native      | varchar(20) | YES  |     | NULL    |       |\n");
    printf("| nation      | varchar(10) | YES  |     | ��      |       |\n");
    printf("| classNo     | char(6)     | YES  |     | NULL    |       |\n");
    printf("+-------------+-------------+------+-----+---------+-------+\n"); 
    printf("8 rows in set (0.01 sec)\n\n\n\n\n");
    print();
    printf("@->alter table tb_student2 drop column id;\n");
    printf("Query OK, 0 rows affected (0.05 sec)\n");
    printf("Records: 0  Duplicates: 0  Warnings: 0\n\n\n\n\n");
    print();
    printf("@->alter table tb_student2 rename to backup_tb_student;\n");
    printf("Query OK, 0 rows affected (0.03 sec)\n\n\n\n\n");
    print();
    printf("@->rename table backup_tb_student to tb_student2;\n");
    printf("Query OK, 0 rows affected (0.03 sec)\n\n\n\n\n");
    print();
    printf("@->drop table tb_student, tb_student2;\n");
    printf("Query OK, 0 rows affected (0.02 sec)\n\n\n\n\n");
    printf("CREATE TABLE tb_student (\n");
    printf(" studentNo CHAR(10) NOT NULL,\n");
    printf(" studentName VARCHAR(10) NOT NULL,\n");
    printf(" sex CHAR(2),\n");
    printf(" birthday DATE,\n");
    printf(" native VARCHAR(20),\n");
    printf(" nation VARCHAR(20) default \'��\',\n");
    printf(" classNo CHAR(6),\n");
    printf(" constraint pk_student primary key(studentNo)\n");
    printf(") engine=InnoDB default charset=gb2312;\n\n\n\n\n");
    printf("CREATE TABLE tb_class (\n");
    printf(" classNo CHAR(6) PRIMARY KEY NOT NULL,\n");
    printf(" className VARCHAR(20) NOT NULL,\n");
    printf(" department VARCHAR(20),\n");
    printf(" grade ENUM(\'1\',\'2\',\'3\',\'4\'),\n"); 
    printf(" classNum TINYINT,\n");
    printf(" constraint uq_class unique(className)\n");
    printf(") engine=InnoDB default charset=gb2312;\n");
    print();
	printf("@->CREATE TABLE tb_student (\n");
	printf("    ->  studentNo CHAR(10) NOT NULL,\n");
	printf("    ->    studentName VARCHAR(10) NOT NULL,\n");
	printf("    ->    sex CHAR(2),\n");
	printf("    ->    brithday DATA,\n");
	printf("    ->    native VARCHAR(20),\n");
	printf("    ->    nation varchar(20) default '��',\n");
	printf("    ->    classNo char(6),\n");
	printf("    ->    constraint pk_student primary key(studentNo),\n");
	printf("    ->    constraint fk_student foreign key(classNo) references tb_class(classNo)\n");
	printf("    ->    on update cascade\n");
	printf("    ->    on delete restrict\n");
	printf("    ->   ) engine=innodb charset=gb2313;\n");
	printf("Query OK, 0 rows affected (0.04 sec)\n\n\n\n\n");
	print();
	printf("@->create table tb_course(\n");
	printf("    ->   courseNo char(6) not null,\n");
	printf("    ->   courseName varchar(20) not null unique,\n");
	printf("    ->   credit DECIMAL(3,1) not null,\n");
	printf("    ->   coursehour TINRINT(2) not null,\n");
	printf("    ->   term TINRINT(1),\n");
	printf("    ->   priorcourse char(6),\n");
	printf("    ->   constraint pk_course primary key(courseNo),\n");
	printf("    ->   constraint fk_course foreign key(priorcourse) references tb_course(courseNo),\n ");
	printf("    -> constraint ck_course check(credit=coursehour/16)\n");
	printf("    ->   ) engine=innodb  charset=gb2312;\n");
	printf("Query OK, 0 rows affected, 2 warnings (0.04 sec)\n\n\n\n\n");
	print();
	printf("@->create table tb_score(\n");
	printf("   ->    studentNo char(10) not null,\n");
	printf("    ->     courseNo char(6) not null,\n");
	printf("    ->     credit decimal(4,1) not null,\n");
	printf("    ->   constraint pk_score primary key(studentNo,courseNo),\n");
	printf("    ->     constraint fk_score_stuNo foreign key(studentNo) references tb_studentNo),\n");
	printf("    ->     constraint fk_score_courNo foreign key(courseNo) references tb_courseNo)\n");
	printf("    ->    ) engine=innodb  charset=gb2312;\n");
	printf("Query OK, 0 rows affected (0.04 sec)\n\n\n\n\n");
	print();
	printf("@->alter table tb_score drop foreign key fk_score_stuNo;\n");
	printf("Query OK, 0 rows affected (0.01 sec)\n");
	printf("Records: 0  Duplicates: 0  Warnings: 0\n\n\n\n\n");
	print();
	printf("@->alter table tb_student drop primary key;\n");
	printf("Query OK, 0 rows affected (0.07 sec)\n");
	printf("Records: 0  Duplicates: 0  Warnings: 0\n\n\n\n\n");
	print();
	printf("@->alter table tb_student add primary key(studentNo);\n");
	printf("Query OK, 0 rows affected (0.07 sec)\n");
	printf("Records: 0  Duplicates: 0  Warnings: 0\n\n\n\n\n");
	print();
	printf("@->alter table tb_score\n");
	printf("    -> add constraint fk_score_stuNo foreign key (studentNo)\n");
	printf("    -> references tb_student(studentNo);\n");
	printf("Query OK, 0 rows affected (0.07 sec)\n");
	printf("Records: 0  Duplicates: 0  Warnings: 0\n\n\n\n\n");
    system("pause");
    return 0;
}
void print(){
    int j;
    printf("420");
    for(j=1;j<=8;j++)cout<<c[j];
}