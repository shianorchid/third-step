rika = [65, 80, 67, 35, 58, 60, 72, 75, 68, 92, 36, 50, 25, 85, 46, 42, 78, 62, 84, 70]

eigo = [44, 87, 100, 63, 52, 60, 58, 73, 55, 86, 29, 56, 89, 23, 65, 84, 64, 27, 86, 84]

rika_avg = rika.sum/20
eigo_avg = eigo.sum/20
puts " ;< "
printf('平均点：理科%.1f点, 英語%.1f点', rika_avg, eigo_avg) 
puts 

rika_arr = rika.map{|x| (x - rika_avg) ** 2}
eigo_arr = eigo.map{|x| (x - eigo_avg) ** 2}

rika_hyohen = Math.sqrt(rika_arr.sum / 20).round(3)
eigo_hyohen = Math.sqrt(eigo_arr.sum / 20).round(3)
 
printf('標準偏差： 理科%.2f, 英語%.2f',rika_hyohen, eigo_hyohen)
puts

printf('合計点： 理科%d点, 英語%d点', rika.sum, eigo.sum)
puts

rika_hensa = rika.map{|x| (10*(x-rika_avg)/rika_hyohen+50).round(3) }
eigo_hensa = eigo.map{|x| (10*(x-eigo_avg)/eigo_hyohen+50).round(3) }

printf('偏差値： 理科')
puts
p rika_hensa
printf('偏差値： 英語')
puts
p eigo_hensa


printf('点数の高い順：理科')
puts
p rika.sort.reverse
printf('点数の高い順：英語')
puts
p eigo.sort.reverse



