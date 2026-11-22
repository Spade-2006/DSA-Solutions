select S.name
from Orders O
join Company C on O.com_id = C.com_id and C.name = 'RED'
right join SalesPerson S on O.sales_id = S.sales_id
where O.order_id is null;