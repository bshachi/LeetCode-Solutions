select t1.name as Department, e1.name as Employee, salary as Salary
from Employee as e1
inner join
(select d.id, d.name, max(salary) as max_sal
from Department as d
inner join Employee as e
on d.id = e.departmentId
group by d.id) as t1
on e1.departmentId = t1.id 
where salary = max_sal;