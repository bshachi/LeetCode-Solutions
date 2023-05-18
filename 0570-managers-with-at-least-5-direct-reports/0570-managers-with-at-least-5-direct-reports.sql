select e2.name 
from Employee as e1
inner join Employee as e2
on e1.managerId = e2.id
group by e1.managerId
having count(*)>4;