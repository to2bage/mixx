/*
    随机将12枚硬币等分成3份, 每份4枚; 标记为A, B, C三份
    将A放于左侧, B放于右侧, 用天平称量, 有下述三种情况:
    1. 天平平衡
        说明A, B中没有假币, 假币在C中, 将C中的硬币编号为 甲乙丙丁
        取甲乙用天平称量, 若平衡, 说明甲乙是真币, 丙丁有一枚假币
                              取甲丙称量, 若平衡, 则丁是假币
                                        若不平衡, 则丙是假币
                        若不平衡, 说明甲乙中有假币, 丙丁都是真币
                              取甲丙称量, 若平衡, 则乙是假币
                                        若不平衡, 则甲是假币
    2. A 重于 B
       说明假币必然在A, B中, C中的硬币都是真币.
       将A中的硬币编号为1234, B中的硬币编号为5678, C中的硬币编号为甲乙丙丁
       选125放于左侧, 34甲放于右侧, 天平有下述的三种情况:
       1) 天平平衡: 说明B中的678中有假币, 且假币轻
       2) 125 重于 34甲:
          说明假币不可能是678
              如果假币是5: 则12 == 34 且 125 > 34甲, 则5应该比真币重, 从而推导出B重于A, 与题设矛盾, 所以假币不可能是5
              由上推出,5必然是真币. 则假币在A中, 且由于A重于B, 说明假币重于真币, 推导出假币必然在12中.
       3) 125 轻于 34甲:
          说明假币不可能是678
              如果假币是5: 则12 == 34 且 125 < 34甲, 则5应该比真币轻, 能够推导出A重于B, 存在5是假币的可能;
              如果假币不是5: 则 12 < 34, 假币在A中, 又因为A重于B的, 说明假币是重的, 即假币在34中.
         
    3. A 轻于 B
*/