-- Write your PostgreSQL query statement below
select Distinct author_id as id 
from Views
 Where author_id = viewer_id
Order By id asc;