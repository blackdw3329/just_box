#5장 SQL 기초

#select version();
#select current_date(),current_time(),now();
#select user();
#show databases;

drop database if exists univDB;
create database if not exists univDB;

use univDB;

create table 학생
	( 	학번 char(4) not null,
		이름 varchar(20) not null,
        주소 varchar(50) null default '미정',
        학년 int not null,
        나이 int null,
        성별 char(1) not null,
        휴대폰번호 char(14) null,
        소속학과 varchar(20) null,
        primary key(학번)
    );

create table 과목
(
	과목번호 char(4) not null primary key,
    이름 varchar(20) not null,
    강의실 char(4) not null,
    개설학과 varchar(20) not null,
    시수 int not null
);

create table 수강
(
	학번 char(4) not null,
    과목번호 char(4) not null,
    신청날짜 date not null,
    중간성적 int null default 0,
	기말성적 int null default 0,
    평가학점 char(1) null,
    primary key(학번, 과목번호)
); 
insert into 학생
values ('s001','김연아','서울 서초',4,23,'여','010-1111-2222','컴퓨터');
insert into 학생
values ('s002','홍길동',default,1,26,'남',null,'통계');
insert into 학생
values ('s003','이승엽',null,3,30,'남',null,'정보통신');
insert into 학생
values ('s004','이영애','경기 분당',2,null,'여','010-4444-5555','정보통신');
insert into 학생
values ('s005','송윤아','경기 분당',4,23,'여','010-6666-7777','컴퓨터');
insert into 학생
values ('s006','홍길동','서울 종로',2,26,'남','010-8888-9999','컴퓨터');
insert into 학생
values ('s007','이은진','경기 과천',1,23,'여','010-2222-3333','경영');

insert into 과목
values ('c001','데이터베이스','126','컴퓨터',3);
insert into 과목
values ('c002','정보보호','137','정보통신',3);
insert into 과목
values ('c003','모바일웹','128','컴퓨터',3);
insert into 과목
values ('c004','철학개론','117','철학',2);
insert into 과목
values ('c005','전공글쓰기','120','교양학부',1);

insert into 수강
values ('s001','c002','2019-09-03',93,98,'A');
insert into 수강
values ('s004','c005','2019-03-03',72,78,'C');
insert into 수강
values ('s003','c002','2017-09-06',85,82,'B');
insert into 수강
values ('s002','c001','2018-03-10',31,50,'F');
insert into 수강
values ('s001','c004','2019-03-05',82,89,'B');
insert into 수강
values ('s004','c003','2020-09-03',91,94,'A');
insert into 수강
values ('s001','c005','2020-09-03',74,79,'C');
insert into 수강
values ('s003','c001','2019-03-03',81,82,'B');
insert into 수강
values ('s004','c002','2018-03-05',92,95,'A');




use univDB;
select database();
show tables;
desc 학생;

select 이름,주소 from 학생;

#전체 열 선택 *
select 학번,이름,주소,학년,나이,성별,휴대폰번호,소속학과 from 학생;
select* from 학생;

#중복제거 distinct
select distinct 소속학과 from 학생;

select 소속학과 from 학생;
select all 소속학과 from 학생;

select 이름,학년,소속학과,휴대폰번호 from 학생 where 학년>=2 and 소속학과='컴퓨터';

select 이름,학년,소속학과,휴대폰번호 from 학생 where(학년>=1 and 학년<=3)or not(소속학과='컴퓨터');
select 이름,학년,소속학과,휴대폰번호 from 학생 where(학년 between 1 and 3)or not(소속학과='컴퓨터');

select 이름, 학년, 소속학과 from 학생 where 소속학과='컴퓨터' or 소속학과='정보통신' order by 학년 asc;

select * from 학생 order by 학년 asc, 이름 desc;

#limit 처음 N개의 행만 반환 offset M 시작인덱스 M
select * from 수강 order by 중간성적 desc limit 3 offset 0;

#limit N, M => N인덱스부터 M개 행만 반환
select * from 수강 order by 중간성적 desc limit 1, 3;

select count(*) from 학생;
select * from 학생;

select count(*) as 학생수1, count(주소) as 학생수2, count(distinct 주소) as 학생수3 from 학생;

select avg(나이) '여학생 평균나이' from 학생 where 성별='여';

select 성별, max(나이) as '최고나이', min(나이) as '최저나이' from 학생 group by 성별;

select 나이, count(*) as '나이별 학생수' from 학생 where(나이 between 20 and 29) group by 나이;

select 학번, 이름 from 학생 where 이름 like '이%';

select 이름, 휴대폰번호 from 학생 where 휴대폰번호 is null;

select 학번 from 학생 where 성별 = "여" 
union 
select 학번 from 수강 where 평가학점 = 'A';

select 이름 from 학생 where 학번 in ('s001','s003','s004');
select * from 학생 where 학번 in ('s001','s003','s004');

select 이름 from 학생 where 학번 in (select 학번 from 수강 where 과목번호='c002');

select 이름 from 학생 where 학번 in (select 학번 from 수강 where 과목번호=(select 과목번호 from 과목 where 이름='정보보호'));

select 이름 from 학생 where exists (select * from 수강 where 수강.학번 = 학생.학번 and 과목번호='c002');

select * from 학생 cross join 수강;

select * from 학생 join 수강 on 학생.학번 = 수강.학번;

set SQL_SAFE_UPDATES = 0;

create table 학생1 as (select * from 학생);
create table 과목1 as (select * from 과목);
create table 수강1 as (select * from 수강);

insert into 학생1
values ('g001','김연아2','서울 서초',4,23,'여','010-1111-2222','컴퓨터');

insert into 학생1(이름, 주소, 학년, 나이, 성별, 휴대폰번호, 소속학과, 학번)
values ('홍길동2',default,1,26,'남',NULL,'통계','g002');

insert into 학생1 (이름,학년,나이,성별,소속학과,학번)
values ('홍길동2',1,26,'남','통계','g002');

insert into 학생1 (학년,나이,성별,소속학과,학번,이름)
values (3,30,'남','정보통신','g003','이승엽2');

update 학생1 set 학년=3 where 이름='이은진';

select * from 학생1 where 이름='이은진';

update 학생1 set 학년=학년+1, 소속학과='자유전공학부'
where 학년=4;

select * from 학생1;

update 학생1 set 소속학과 = null where 학번 not in (select 학번 from 수강1);

select * from 학생1;

update 수강1 set 학번 = ( select 학번 from 학생1 where 이름 = '이은진' ) where 학번 ='s003';
select * from 수강1 where 학번 = 's003' or 학번 = 's007';

delete from 학생1 where 이름 = '송윤아';
select * from 학생1;

delete from 학생1;

create table 과목2(과목번호 char(4) not null primary key, 이름 varchar(20) not null, 강의실 char(5) not null, 개설학과 varchar(20) not null, 시수 int not null);
desc 과목2;

#6장 SQL 활용
create table 학생2 (
학번 char(4) not null,
이름 varchar(20) not null,
주소 varchar(50) default '미정',
학년 int not null,
나이 int null,
성별 char(1) not null,
휴대폰번호 char(13) null,
소속학과 varchar(20) null,
primary key (학번),
unique (휴대폰번호));

create table 수강2(
학번 char(4) not null,
과목번호 char(4) not null,
신청날짜 date not null,
중간성적 int null default 0,
기말성적 int null default 0,
평가학점 char(1) null,
primary key (학번, 과목번호),
foreign key (학번) references 학생2(학번),
foreign key(과목번호) references 과목2(과목번호));

insert into 과목2 select * from 과목;
insert into 학생2 select * from 학생;
insert into 수강2 select * from 수강;


#데이터 수정 ALTER문
alter table 학생2 add 등록날짜 date not null default '2019-12-30';
select * from 학생2;

#테이블 삭제 DROP문
alter table 학생2 drop column 등록날짜;

drop table 수강2;
drop table 과목2;

select * from 과목2; -- 과목2 를 drop을 했기 때문에 오류
desc 과목2;

show tables;


# SQL 데이터 제어문

#계정생성 CREATE USER문
create user 'user1'@'127.1.1.1'identified by '1111';
create user 'user2'@'localhost'identified by '2222';
create user 'user3'@'192.182.10.2'identified by '3333';
create user 'user4'@'%'identified by '4444';

select host, user from mysql.user;

#권한부여: GRANT
grant insert, update, delete on univDB.* to 'user1'@'127.1.1.1';
grant all on *.* to 'user4'@'%'with grant option;
grant select on univDB.학생 to 'user2'@'localhost';

#사용자계정 권한 확인
show grants for 'user1'@'127.1.1.1'; -- user1 사용자의 권한 표시
show grants; -- 현재 접속 사용자의 권한 표시

#권한 철회: REVOKE
revoke delete on univDB.* from 'user1'@'127.1.1.1';

#계정 삭제: DROP USER
drop user 'user1'@'127.1.1.1';

#사용자 계정 생성
create user 'manager'@'%' identified by '1234';
grant all on *.* to 'manager'@'%' with grant option;

select user(); -- 현재 MySQL 사용자 표시



#뷰 view

#뷰 생성 CREATE VIEW
create view v1_고학년학생(학생이름, 나이, 성, 학년)
as select 이름, 나이, 성별, 학년 from 학생 where 학년>=3 and 학년<=4;

select * from v1_고학년학생; -- v1_고학년학생 뷰의 데이터 확인
show tables; -- 뷰 목록


create view v2_과목수강현황(과목번호, 강의실, 수강인원수)
as select 과목.과목번호,강의실,count(과목.과목번호) from 과목 join 수강 on 과목.과목번호 = 수강.과목번호
group by 과목.과목번호;

select * from v2_과목수강현황
