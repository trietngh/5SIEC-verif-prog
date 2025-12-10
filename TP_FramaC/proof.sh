FICH=$1
frama-c -wp ${FICH}  -warn-signed-overflow -warn-unsigned-overflow -warn-signed-downcast -warn-unsigned-downcast -wp-prover alt-ergo -wp-report report_spec -wp-model caveat+real+cast -wp-extern-arrays -wp-extensional -wp-split -wp-report-basename ${FICH}
