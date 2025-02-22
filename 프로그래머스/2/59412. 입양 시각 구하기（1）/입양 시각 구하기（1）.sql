

select hour(datetime) as hour, count(*) as count
from animal_outs a
where hour(datetime) between 9 and 19
group by hour
order by hour