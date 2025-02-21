select factory_id, factory_name, address
from food_Factory
where address like '강원도%'
order by factory_id asc;