--PL/SQL T-SQL  标准化扩展
select * from table1 t
create table t
create view  v
drop table t;
select distinct top from .. where ..group by .. having .. order by .. 
select salary*(1+0.1) from employees
select distinct id from employees
select id,name from employees where name like 'B%' and id>5-- _:one charactor;%:any char.
where name = NULL;
select employee_id.first_name,salary from employees where salary>100 order by salary,first_name; desc big->small
select job_id,salary from employees order by job_id;
select sum(salary),avg(salary),max(salary),count(*) from employees having avg(salary) > 1000
--multi table
select employee_id,name,department_name from employees,departments;--笛卡尔积
select t.id from employees t;





