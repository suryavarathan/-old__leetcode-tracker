-- Last updated: 7/14/2026, 3:29:09 PM
# Write your MySQL query statement below
# Write your MySQL query statement below
select user_id,concat(upper(substring(name,1,1)),lower(substring(name,2))) as name from Users
order by user_id;