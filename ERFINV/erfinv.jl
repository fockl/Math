using SpecialFunctions

println(erfinv(0.5))
println(erfinv(0.9))
println(erfinv(0.99))

function main(N)
  for i in 0:N-1
    erfinv(i/N)
  end
end

@time main(1E8)
