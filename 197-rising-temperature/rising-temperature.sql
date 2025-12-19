-- # Write your MySQL query statement below
SELECT p1.id
FROM Weather p1
JOIN Weather p2
ON p2.temperature<p1.temperature
AND p1.recordDate = DATE_ADD(p2.recordDate, INTERVAL 1 DAY)
UNION
SELECT p3.id
FROM Weather p3
JOIN Weather p4
ON p4.temperature<p3.temperature
AND p3.recordDate = DATE_ADD(p4.recordDate, INTERVAL 1 DAY);

