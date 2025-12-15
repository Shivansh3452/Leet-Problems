SELECT e.name as Employee
FROM Employee e
JOIN Employee m ON e.managerId=m.id
WHERE e.salary>m.salary

-- JOIN does this in table
-- +------+---------+----------+-------------+------+---------+----------+
-- | e.id | e.name  | e.salary | e.managerId | m.id | m.name  | m.salary |
-- +------+---------+----------+-------------+------+---------+----------+
-- | 1    | Joe     | 70000    | 3           | 3    | Sam     | 60000    | ← Joe & his manager Sam
-- | 2    | Henry   | 80000    | 4           | 4    | Max     | 90000    | ← Henry & his manager Max