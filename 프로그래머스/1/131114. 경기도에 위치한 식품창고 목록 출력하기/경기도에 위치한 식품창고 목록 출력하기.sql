select warehouse_id, warehouse_name, address, ifnull(freezer_YN, 'N') as freezer_YN
from food_warehouse
where address like '경기%'
order by warehouse_id