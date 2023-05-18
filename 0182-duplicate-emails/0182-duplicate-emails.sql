select distinct P1.email
from Person as P1
inner join Person as P2
on P1.email = P2.email
where not P1.id = P2.id; 