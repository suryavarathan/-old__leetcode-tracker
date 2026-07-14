-- Last updated: 7/14/2026, 3:26:27 PM
# Write your MySQL query statement below
SELECT employee_id, department_id
FROM Employee
GROUP BY employee_id
HAVING COUNT(employee_id) = 1

UNION

SELECT employee_id, department_id
FROM Employee
WHERE primary_flag = 'Y';