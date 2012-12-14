; RUN: llc < %s -march=unicore32

define i32 @test(i32 %a1) {
  ret i32 %a1
}
