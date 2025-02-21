select title, b.board_id as BOARD_ID, reply_id, r.writer_id as WRITER_ID, r.contents as CONTENTS, date_format(r.created_date, '%Y-%m-%d') as created_date
from used_goods_board as b
join used_goods_reply as r on b.BOARD_ID = r.board_id
where b.created_date like '2022-10%'
order by r.created_date asc, title asc;