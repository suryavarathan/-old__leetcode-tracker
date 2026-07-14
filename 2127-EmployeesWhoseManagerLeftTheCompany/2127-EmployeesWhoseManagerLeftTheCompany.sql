-- Last updated: 7/14/2026, 3:22:23 PM
SELECT e.employee_id 
FROM Employees e
LEFT JOIN Employees ee
ON e.manager_id = ee.employee_id
WHERE 
    e.salary < 30000
    AND e.manager_id IS NOT NULL
    AND ee.employee_id IS NULL
ORDER BY e.employee_id;