-- Write your PostgreSQL query statement below

Select E1.name from Employee E1  join Employee E2 on E1.id = E2.managerId 
group by E1.id , E1.name
having count(E2.managerId) >= 5;