-- Last updated: 7/14/2026, 3:23:54 PM
# Write your MySQL query statement below
select "Low Salary" as category,count(*) as accounts_count 
from Accounts
where income < 20000
union
select "Average Salary" as category,count(*) as accounts_count 
from Accounts
where income >= 20000 and income <= 50000
union
select "High Salary" as category,count(*) as accounts_count 
from Accounts
where income > 50000