-- Last updated: 7/14/2026, 3:29:22 PM
# Write your MySQL query statement below
select s.machine_id, round(avg(e.timestamp - s.timestamp),3) as processing_time
from activity s
join activity e on e.machine_id = s.machine_id
where s.activity_type = 'start' and e.activity_type = 'end'
group by s.machine_id;