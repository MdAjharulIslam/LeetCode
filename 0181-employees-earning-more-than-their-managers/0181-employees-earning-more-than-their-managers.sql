-- Write your PostgreSQL query statement below
select e.name as employee
from Employee e
join Employee m on e.managerId = m.id
where m.salary < e.salary;