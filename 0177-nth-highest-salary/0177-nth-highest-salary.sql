CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  RETURN (
      # Write your MySQL query statement below.
    select DISTINCT salary from(
        select salary, DENSE_RANK() OVER(order by salary DESC) rnk from Employee
    ) t
    where rnk=N
  );
END