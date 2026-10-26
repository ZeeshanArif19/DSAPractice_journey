# Write your MySQL query statement below
with FirstLogin as (
    select player_id,min(event_date) as firstlog
    from Activity
    group by player_id
)
select round(count(DISTINCT case when DATEDIFF(a.event_date,fl.firstlog)=1 then a.player_id end)/count(DISTINCT a.player_id),2) as fraction
from Activity a
right join FirstLogin fl on a.player_id=fl.player_id
