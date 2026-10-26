# Write your MySQL query statement below
with DeptMax as (
    select departmentId,max(salary) as max_sal from Employee
    group by departmentId
)
select d.name as Department,e.name as Employee,e.salary as Salary
from Employee e
join Department d on e.departmentId=d.id
join DeptMax m on e.departmentId=m.departmentId
where e.salary=m.max_sal