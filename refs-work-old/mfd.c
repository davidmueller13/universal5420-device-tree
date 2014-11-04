
	/* The addresses here have yet to be corrected */
	i2c_max77693: i2c-gpio {
		compatible = "i2c-gpio";
		gpios = <&gpm2 0 GPIO_ACTIVE_HIGH>, <&gpm2 1 GPIO_ACTIVE_HIGH>;
		i2c-gpio,delay-us = <2>;
		#address-cells = <1>;
		#size-cells = <0>;
		status = "okay";

		max77693@66 {
			compatible = "maxim,max77693";
			interrupt-parent = <&gpx1>;
			interrupts = <5 2>;
			reg = <0x66>;

			regulators {
				esafeout1_reg: ESAFEOUT1@1 {
					regulator-name = "ESAFEOUT1";
					regulator-boot-on;
				};
				esafeout2_reg: ESAFEOUT2@2 {
					regulator-name = "ESAFEOUT2";
				};
				charger_reg: CHARGER@0 {
					regulator-name = "CHARGER";
					regulator-boot-on;
					regulator-min-microamp = <60000>;
					regulator-max-microamp = <2580000>;
				};
			};

			charger {
				compatible = "maxim,max77693-charger";

				maxim,constant-microvolt = <4350000>;
				maxim,min-system-microvolt = <3600000>;
				maxim,thermal-regulation-celsius = <100>;
				maxim,battery-overcurrent-microamp = <3500000>;
				maxim,charge-input-threshold-microvolt = <4300000>;
			};
 		};
 	};
};