-- Last updated: 7/14/2026, 3:24:42 PM
# Write your MySQL query statement below
SELECT employee_id,
    CASE WHEN substring(name, 1, 1) <> 'M' AND employee_id % 2 <> 0 THEN salary
    ELSE 0 END AS bonus  
FROM Employees
ORDER BY employee_id