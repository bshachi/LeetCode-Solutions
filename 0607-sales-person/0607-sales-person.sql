select s.name
from SalesPerson as s
left join
(select sales_id as sid
from Orders as o
inner join
Company as c
on o.com_id = c.com_id
where name = "RED") as t
on sales_id = sid
where sid is null;
