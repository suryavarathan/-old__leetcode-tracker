-- Last updated: 7/14/2026, 3:27:47 PM
# Write your MySQL query statement below
select e1.reports_to as employee_id,
e2.name,
count(e1.employee_id) as reports_count,
round(avg(e1.age)) as average_age
from employees as e1
join employees as e2
on e1.reports_to = e2.employee_id
group by employee_id
order by e1.reports_to;