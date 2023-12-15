add_executable(hello_pdf hello_pdf.c)
target_link_libraries(hello_pdf cairo)

add_executable(taichi taichi.c)
target_link_libraries(taichi cairo)
