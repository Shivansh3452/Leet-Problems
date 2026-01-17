# Write your MySQL query statement below
SELECT d.name as Department,e.name as Employee,e.salary as Salary
FROM Department d, Employee e
WHERE e.departmentId=d.id
AND (e.departmentId,e.salary) IN (SELECT departmentId,MAX(salary)
                                  FROM Employee
                                  GROUP BY departmentId)