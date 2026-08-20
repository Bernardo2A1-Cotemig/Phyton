package com.example.prova3xnn_viagens

import android.os.Bundle
import androidx.activity.ComponentActivity
import androidx.activity.compose.setContent
import androidx.compose.foundation.layout.*
import androidx.compose.material3.*
import androidx.compose.runtime.*
import androidx.compose.ui.Modifier
import androidx.compose.ui.unit.dp

enum class TelaViagem {
    MENU,
    CALCULADORA_COMBUSTIVEL,
    ORCAMENTO_DIARIO
}

class MainActivity : ComponentActivity() {

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)

        setContent {

            var telaAtual by remember {
                mutableStateOf(TelaViagem.MENU)
            }

            when (telaAtual) {

                TelaViagem.MENU -> {
                    TelaMenu(
                        onNavegar = {
                            telaAtual = it
                        }
                    )
                }

                TelaViagem.CALCULADORA_COMBUSTIVEL -> {
                    TelaCombustivel(
                        onVoltar = {
                            telaAtual = TelaViagem.MENU
                        }
                    )
                }

                TelaViagem.ORCAMENTO_DIARIO -> {
                    TelaOrcamento(
                        onVoltar = {
                            telaAtual = TelaViagem.MENU
                        }
                    )
                }
            }
        }
    }
}

@Composable
fun TelaMenu(onNavegar: (TelaViagem) -> Unit) {

    Column(
        modifier = Modifier.padding(20.dp)
    ) {

        Text("Hub de Viagens")

        Spacer(modifier = Modifier.height(20.dp))

        Button(
            onClick = {
                onNavegar(TelaViagem.CALCULADORA_COMBUSTIVEL)
            }
        ) {
            Text("Calcular Combustível")
        }

        Spacer(modifier = Modifier.height(10.dp))

        Button(
            onClick = {
                onNavegar(TelaViagem.ORCAMENTO_DIARIO)
            }
        ) {
            Text("Calcular Orçamento Diário")
        }
    }
}

@Composable
fun TelaCombustivel(onVoltar: () -> Unit) {

    var distancia by remember { mutableStateOf("") }
    var consumo by remember { mutableStateOf("") }
    var litros by remember { mutableStateOf(0.0) }

    Column(
        modifier = Modifier.padding(20.dp)
    ) {

        Text("Calculadora de Combustível")

        Spacer(modifier = Modifier.height(15.dp))

        TextField(
            value = distancia,
            onValueChange = {
                distancia = it
            },
            label = {
                Text("Distância total (Km)")
            }
        )

        Spacer(modifier = Modifier.height(10.dp))

        TextField(
            value = consumo,
            onValueChange = {
                consumo = it
            },
            label = {
                Text("Consumo médio (Km/L)")
            }
        )

        Spacer(modifier = Modifier.height(15.dp))

        Button(
            onClick = {

                val distanciaNumero =
                    distancia.toDoubleOrNull() ?: 0.0

                val consumoNumero =
                    consumo.toDoubleOrNull() ?: 0.0

                if (consumoNumero > 0) {
                    litros = distanciaNumero / consumoNumero
                } else {
                    litros = 0.0
                }
            }
        ) {
            Text("Calcular Litros")
        }

        Spacer(modifier = Modifier.height(15.dp))

        Text("Litros necessários: $litros")

        Spacer(modifier = Modifier.height(20.dp))

        Button(
            onClick = onVoltar
        ) {
            Text("Voltar")
        }
    }
}

@Composable
fun TelaOrcamento(onVoltar: () -> Unit) {

    var orcamento by remember { mutableStateOf("") }
    var dias by remember { mutableStateOf("") }
    var limiteDiario by remember { mutableStateOf(0.0) }

    Column(
        modifier = Modifier.padding(20.dp)
    ) {

        Text("Orçamento Diário")

        Spacer(modifier = Modifier.height(15.dp))

        TextField(
            value = orcamento,
            onValueChange = {
                orcamento = it
            },
            label = {
                Text("Orçamento Total da Viagem (R$)")
            }
        )

        Spacer(modifier = Modifier.height(10.dp))

        TextField(
            value = dias,
            onValueChange = {
                dias = it
            },
            label = {
                Text("Quantidade de Dias")
            }
        )

        Spacer(modifier = Modifier.height(15.dp))

        Button(
            onClick = {

                val orcamentoNumero =
                    orcamento.toDoubleOrNull() ?: 0.0

                val diasNumero =
                    dias.toDoubleOrNull() ?: 0.0

                if (diasNumero > 0) {
                    limiteDiario = orcamentoNumero / diasNumero
                } else {
                    limiteDiario = 0.0
                }
            }
        ) {
            Text("Calcular Limite Diário")
        }

        Spacer(modifier = Modifier.height(15.dp))

        Text("Limite por dia: R$ $limiteDiario")

        Spacer(modifier = Modifier.height(20.dp))

        Button(
            onClick = onVoltar
        ) {
            Text("Voltar")
        }
    }
}
