using SpecialFunctions

println(erfinv(0.5))
println(erfinv(0.9))
println(erfinv(0.99))

N = 1E8

function main()
  for i in 0:N-1
    erfinv(i/N)
  end
end

@time main()
