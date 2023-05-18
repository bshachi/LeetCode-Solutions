select customer_number
from Orders
group by customer_number
having count(*) = 
(select max(c) from
(select count(*) as c, customer_number 
from Orders
group by customer_number) as t1);