Delete from Person
using Person 
inner join
(select min(Id) as Id, email from Person
group by email) as t1
on t1.email = Person.email
where not Person.Id = t1.Id;